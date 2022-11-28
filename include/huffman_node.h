/*
** EPITECH PROJECT, 2022
** Huffman_coding
** File description:
** huffman_node
*/

#ifndef HUFFMAN_NODE_H_
#define HUFFMAN_NODE_H_
#include <stdint.h>

struct huffman_node_s
{
    uint64_t occurrence;
    uint8_t value;
    struct huffman_node_s* left;
    struct huffman_node_s* right;
};

struct huffman_node_s* create_node(uint64_t occurence, char value, struct huffman_node_s* left, struct huffman_node_s* right);
int init_huffman_node(struct huffman_node_s* node);

#endif /* !HUFFMAN_NODE_H_ */
