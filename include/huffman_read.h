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

int huffman_read_file(char *filename);
int huffman_read_header(char *filename, f_header_data_t *data);

#endif /* !HUFFMAN_READ_H_ */
