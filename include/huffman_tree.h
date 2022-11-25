/*
** EPITECH PROJECT, 2022
** Huffman_coding
** File description:
** huffman_tree
*/

#ifndef HUFFMAN_TREE_H_
#define HUFFMAN_TREE_H_
#include "huffman_node.h"

struct huffman_tree_s
{
    struct huffman_node_s* root;
};

int init_huffman_tree(struct huffman_tree_s* tree);
struct huffman_tree_s* create_tree(void);

#endif /* !HUFFMAN_TREE_H_ */
