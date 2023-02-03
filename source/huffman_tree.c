/*
** EPITECH PROJECT, 2022
** Huffman_coding
** File description:
** huffman_tree
*/

#include <stdlib.h>
#include <stdio.h>
#include "huffman_tree.h"
#include "byte_occurence.h"
#include "generic_list.h"

int huff_tree_init(huff_tree_t* tree)
{
    tree->root = huff_node_create(0, 0, NULL, NULL);

    if (!tree->root) {
        perror("Couldn't allocate tree root memory");
        return -1;
    }
    return 0;
}

huff_tree_t* huff_tree_create(void)
{
    huff_tree_t* tree = malloc(sizeof(huff_tree_t));

    if (!tree) {
        perror("Couldn't allocate tree memory");
        return NULL;
    }
    if (huff_tree_init(tree)) {
        free(tree);
        return NULL;
    }
    return tree;
}

static GList_t *_copy_occurences_to_tree(GList_t *l_occ, GList_t *l_nodes)
{
    GNode_t *current = NULL;

    if (!l_occ || ! l_nodes || l_nodes->size) {
        return NULL;
    }
    current = l_occ->head->next;
    while (current && current != l_occ->tail) {
        byte_occurence_t *b_occ = (byte_occurence_t *)current->data;
        huff_node_t node = {.left = NULL,
                            .right = NULL,
                            .value = b_occ->byte,
                            .occurrence = b_occ->occurence};

        glist_pushback(l_nodes, &node);
        current = current->next;
    }
    return l_nodes;
}

int huff_tree_build(GList_t *l_occ, huff_tree_t *tree)
{
    GList_t *node_list = glist_new(sizeof(huff_node_t));

    _copy_occurences_to_tree(l_occ, node_list);

    while (node_list->size > 1) {

        huff_node_t *last_node = (huff_node_t *)glist_popfront(node_list);
        huff_node_t *slast_node = (huff_node_t *)glist_popfront(node_list);
        if (!last_node || !slast_node) {
            return -1;
        }
        size_t total_occ = last_node->occurrence + slast_node->occurrence;
        huff_node_t *result = huff_node_create(total_occ, '~', last_node, slast_node);
        if (!result)
            return -1;
        glist_pushback(node_list, result);
        free(result);
        glist_sort(node_list, huff_node_comp);
    }
    if (!node_list->head->data)
        return -1;
    tree->root = (huff_node_t *)(node_list->head->data);
    return 0;
}
