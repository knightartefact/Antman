/*
** EPITECH PROJECT, 2022
** Huffman_coding
** File description:
** huffman_tree
*/

#include "huffman_tree.h"
#include <stdlib.h>
#include <stdio.h>

int init_huffman_tree(struct huffman_tree_s* tree)
{
    tree->root = malloc(sizeof(struct huffman_node_s*));

    if (!tree->root)
    {
        printf("Couldn't allocate tree root memory\n");
        return -1;
    }
    return 0;
}

struct huffman_tree_s* create_tree(void)
{
    struct huffman_tree_s* tree = malloc(sizeof(struct huffman_tree_s*));

    if (!tree)
    {
        printf("Couldn't allocate tree memory\n");
        return NULL;
    }
    return tree;
}
