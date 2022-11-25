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
    char value;
    struct huffman_node_s* left;
    struct huffman_node_s* right;
};

#endif /* !HUFFMAN_NODE_H_ */
