/*
** EPITECH PROJECT, 2023
** Antman
** File description:
** huffman_decompressor
*/

#include "huffman_tree.h"
#include "huffman_read.h"

int huffman_decompressor(char *i_filename, char *o_filename)
{
    // 1 Extract file header info
    // 2 Build tree from file
    // 3 Read file into bitstream
    // 4 Decode bit sequences with tree
    huffman_read_file(i_filename);
    return 0;
}