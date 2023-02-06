/*
** EPITECH PROJECT, 2023
** huffman_coding
** File description:
** huffman_write
*/

#ifndef HUFFMAN_WRITE_H_
#define HUFFMAN_WRITE_H_
#include "file_io.h"
#include "generic_list.h"
#include "bitstream.h"
#include "huffman_tree.h"

int huffman_write_file(char *filename, GList_t *codes, file_io_t *input, huff_tree_t *tree);
int huffman_write_file_header(bitstream_t *stream, GList_t *codes, file_io_t *input, huff_tree_t *tree);

#endif /* !HUFFMAN_WRITE_H_ */
