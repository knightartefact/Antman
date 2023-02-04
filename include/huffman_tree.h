/*
** EPITECH PROJECT, 2022
** Huffman_coding
** File description:
** huffman_tree
*/

#ifndef HUFFMAN_TREE_H_
#define HUFFMAN_TREE_H_
#include "huffman_node.h"

typedef struct GList_s GList_t;
typedef struct huffman_tree_s huff_tree_t;

struct huffman_tree_s
{
    huff_node_t* root;
};

huff_tree_t* huff_tree_create(void);
int huff_tree_build(GList_t *occurence_list, huff_tree_t *tree);
int huff_tree_generate_codes(GList_t *codes, huff_node_t *root);
int huff_tree_print(huff_tree_t *tree);
void huff_tree_destroy(huff_tree_t **tree);

#endif /* !HUFFMAN_TREE_H_ */
