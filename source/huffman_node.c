/*
** EPITECH PROJECT, 2022
** Huffman_coding
** File description:
** huffman_node
*/

#include "huffman_node.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

int init_huffman_node(struct huffman_node_s* node)
{
    node->occurrence = 0;
    node->value = 0;
    node->left = NULL;
    node->right = NULL;
    return 0;
}

struct huffman_node_s* create_node(uint64_t occurence, char value, struct huffman_node_s* left, struct huffman_node_s* right)
{
    struct huffman_node_s* node = malloc(sizeof(struct huffman_node_s*));

    if (!node)
    {
        printf("Couldn't allocate node memory\n");
        return NULL;
    }
    node->occurrence = occurence;
    node->value = value;
    node->left = left;
    node->right = right;
    return node;
}
