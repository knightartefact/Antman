/*
** EPITECH PROJECT, 2022
** Huffman_coding
** File description:
** huffman_node
*/

#ifndef HUFFMAN_NODE_H_
#define HUFFMAN_NODE_H_
#include <stdint.h>

typedef struct huffman_node_s huff_node_t;

struct huffman_node_s
{
    uint64_t occurrence;
    uint8_t value;
    huff_node_t* left;
    huff_node_t* right;
};

huff_node_t* huff_node_create(uint64_t occurence, char value, huff_node_t* left, huff_node_t* right);
void huff_node_print(const void *node);
int huff_node_comp(const void *lhs, const void *rhs);
void huff_node_destroy(void *node);

#endif /* !HUFFMAN_NODE_H_ */
