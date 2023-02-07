/*
** EPITECH PROJECT, 2023
** Antman
** File description:
** huffman_decompressor
*/

#include "huffman_tree.h"
#include "huffman_read.h"
#include "huffman_tree.h"

int huffman_decompressor(char *i_filename, char *o_filename)
{
    // 1 Extract file header info
    // 2 Build tree from file
    // 3 Read file into bitstream
    // 4 Decode bit sequences with tree
    bitstream_t *stream = bitstream_create(NULL, "rb");
    f_header_data_t h_data = {0};
    huff_tree_t *tree = huff_tree_create();
    file_io_t *i_file = file_io_create();
    file_io_t *o_file = file_io_create();

    if (!i_file || !o_file)
        return -1;
    if (file_io_load_file(i_filename, "rb", i_file) == -1)
        return -1;

    if (bitstream_load_from_file(stream, i_file->file_ptr) == -1)
        return -1;
    huffman_read_header(stream->file, &h_data);
    if (huffman_rebuild_tree(&h_data, tree) == -1)
        return -1;
    if (file_io_load_file(o_filename, "wb", o_file) == -1) {
        return -1;
    }
    if (huffman_read_file(stream, tree, h_data.last_bit_off, o_file->file_ptr) == -1)
        return -1;
    file_io_free(&i_file);
    file_io_free(&o_file);
    return 0;
}
