/*
** EPITECH PROJECT, 2022
** Huffman_coding
** File description:
** huffman_tree
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "huffman_tree.h"
#include "byte_occurence.h"
#include "generic_list.h"
#include "pair.h"

static void _huff_tree_print_from_root(huff_node_t *root)
{
    if (!root) {
        return;
    }
    printf("Parent: %c -> %ld\n", root->value, root->occurrence);
    if (root->left)
        printf("left child: %c -> %ld\n", root->left->value, root->left->occurrence);
    if (root->right)
        printf("right child: %c -> %ld\n", root->right->value, root->right->occurrence);
    _huff_tree_print_from_root(root->left);
    _huff_tree_print_from_root(root->right);
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

static int is_leaf(huff_node_t *node)
{
    return (!node->left && !node->right);
}

static int _huff_tree_generate_codes(GList_t *codes, char string[], int top, huff_node_t *root)
{
    if (is_leaf(root)) {
        string[top] = 0;
        pair_t data_pair = {.value = root->value,
                            .compressed = strdup(string)};
        glist_pushback(codes, &data_pair);
    }
    if (root->left) {
        string[top] = '0';
        _huff_tree_generate_codes(codes, string, top + 1, root->left);
    }
    if (root->right) {
        string[top] = '1';
        _huff_tree_generate_codes(codes, string, top + 1, root->right);
    }
    return 0;
}

static void _huff_tree_destroy_recursive(huff_node_t *root)
{
    if (!root)
        return;
    _huff_tree_destroy_recursive(root->left);
    _huff_tree_destroy_recursive(root->right);
    free(root);
}

int huff_tree_init(huff_tree_t* tree)
{
    tree->root = NULL;
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

int huff_tree_build(GList_t *l_occ, huff_tree_t *tree)
{
    GList_t *node_list = glist_new(sizeof(huff_node_t));
    huff_node_t *root = NULL;

    _copy_occurences_to_tree(l_occ, node_list);
    while (node_list->size > 1) {

        huff_node_t *first_node = (huff_node_t *)glist_popfront(node_list);
        huff_node_t *second_node = (huff_node_t *)glist_popfront(node_list);
        if (!first_node || !second_node) {
            return -1;
        }
        size_t total_occ = first_node->occurrence + second_node->occurrence;
        huff_node_t *result = huff_node_create(total_occ, '~', first_node, second_node);
        if (!result)
            return -1;
        glist_pushback(node_list, result);
        glist_sort(node_list, huff_node_comp);
        free(result);
    }
    if ((root = (huff_node_t *)(glist_popfront(node_list))) == NULL)
        return -1;
    tree->root = root;
    glist_destroy(&node_list, huff_node_destroy);
    return 0;
}

int huff_tree_generate_codes(GList_t* codes, huff_node_t *root)
{
    char string[64];
    int top = 0;
    _huff_tree_generate_codes(codes, string, top, root);
    return 0;
}

int huff_tree_print(huff_tree_t *tree)
{
    if (!tree->root)
        return -1;
    _huff_tree_print_from_root(tree->root);
    return 0;
}

void huff_tree_destroy(huff_tree_t **tree)
{
    _huff_tree_destroy_recursive((*tree)->root);
    (*tree)->root = NULL;
    free(*tree);
}
