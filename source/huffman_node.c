/*
** EPITECH PROJECT, 2022
** Huffman_coding
** File description:
** huffman_node
*/

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "huffman_node.h"

int huff_node_init(huff_node_t* node)
{
    node->occurrence = 0;
    node->value = 0;
    node->left = NULL;
    node->right = NULL;
    return 0;
}

huff_node_t* huff_node_create(uint64_t occurence, uint8_t value, huff_node_t* left, huff_node_t* right)
{
    huff_node_t* node = malloc(sizeof(huff_node_t));

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

void huff_node_print(const void *node)
{
    huff_node_t* cast_node = (huff_node_t *)node;
    char str[3] = "\\n";
    if (!cast_node)
        return;
    if (cast_node->value != '\n') {
        str[0] = (char)cast_node->value;
        str[1] = 0;
    }
    printf("[%s] -> %ld\n", str, cast_node->occurrence);
}

int huff_node_comp(const void *lhs, const void *rhs)
{
    huff_node_t *h_lhs = (huff_node_t *)lhs;
    huff_node_t *h_rhs = (huff_node_t *)rhs;
    int result = h_lhs->occurrence - h_rhs->occurrence;

    return result;
}

void huff_node_destroy(void *node)
{
}

bool huff_node_is_leaf(huff_node_t *node)
{
    return (!node->left && !node->right);
}
