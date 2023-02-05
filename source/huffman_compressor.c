/*
** EPITECH PROJECT, 2023
** huffman_coding
** File description:
** huffman_compressor
*/

#include "huffman_tree.h"
#include "file_io.h"
#include "byte_occurence.h"
#include "bitstream.h"
#include "pair.h"
#include "generic_list.h"
#include "huffman_write.h"

int huffman_compressor(char *i_filepath, char *o_filepath)
{
    file_io_t* file_io = file_io_create();
    GList_t *occurences = glist_new(sizeof(byte_occurence_t));
    huff_tree_t *huffman_tree = huff_tree_create();
    GList_t *codes_list = glist_new(sizeof(pair_t));

    if (!huffman_tree || !occurences || !codes_list || file_io_load_file(i_filepath, file_io))
        return -1;
    for (int buf_i = 0; file_io->file_buffer[buf_i]; buf_i++) {
        occurence_add(file_io->file_buffer[buf_i], occurences);
    }
    glist_sort(occurences, occurence_comp);
    if (huff_tree_build(occurences, huffman_tree))
        return -1;
    glist_destroy(&occurences, occurence_destroy);
    huff_tree_generate_codes(codes_list, huffman_tree->root);
    huffman_write_file(o_filepath, codes_list, file_io);
    file_io_free(&file_io);
    glist_destroy(&codes_list, pair_destroy);
    huff_tree_destroy(&huffman_tree);
    return 0;
}