/*
** EPITECH PROJECT, 2022
** Huffman_coding
** File description:
** huffman_noe_array
*/

#ifndef HUFFMAN_NOE_ARRAY_H_
#define HUFFMAN_NOE_ARRAY_H_

#include "huffman_node.h"

struct huffman_node_array_s
{
    uint64_t capacity;
    uint64_t size;
    struct huffman_node_s* data;
};

int init_node_array(struct huffman_node_array_s* array);
struct huffman_node_array_s* create_node_array(void);
void node_array_add(struct huffman_node_s new_node, struct huffman_node_array_s* array);
void node_array_pop(struct huffman_node_array_s* array);

#endif /* !HUFFMAN_NOE_ARRAY_H_ */
