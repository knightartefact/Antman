/*
** EPITECH PROJECT, 2023
** Antman
** File description:
** huffman_read
*/

#ifndef HUFFMAN_READ_H_
#define HUFFMAN_READ_H_
#include "file_io.h"
#include "generic_list.h"
#include "bitstream.h"
#include "huffman_tree.h"

typedef struct f_header_data_s f_header_data_t;

struct f_header_data_s {
    size_t original_size;
    size_t header_size;
    uint8_t last_bit_off;
    uint8_t *raw_tree;
};

int huffman_read_file(bitstream_t *stream, huff_tree_t *tree, f_header_data_t *data, FILE *out);
int huffman_read_header(FILE *file, f_header_data_t *data);
int huffman_rebuild_tree(f_header_data_t *data, huff_tree_t *tree);

#endif /* !HUFFMAN_READ_H_ */
