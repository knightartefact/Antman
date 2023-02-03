/*
** EPITECH PROJECT, 2022
** Huffman_coding
** File description:
** main
*/

#include <unistd.h>
#include "file_io.h"
#include "huffman_tree.h"
#include "byte_occurence.h"
#include "generic_list.h"

int main(int ac, char** av)
{
    struct file_io_s* file_io = file_io_create();

    if (!file_io || ac < 2)
    {
        printf("Please enter a valid filename\n");
        return 1;
    }
    if (file_io_load_file(av[1], file_io))
    {
        return 1;
    }
    GList_t *occurences = glist_new(sizeof(struct byte_occurence_s));
    if (!occurences)
        return -1;
    for (int buf_i = 0; file_io->file_buffer[buf_i]; buf_i++)
    {
        occurence_add(file_io->file_buffer[buf_i], occurences);
    }
    glist_sort(occurences, occurence_comp);

    huff_tree_t *huffman_tree = huff_tree_create();
    if (!huffman_tree)
        return -1;
    if (huff_tree_build(occurences, huffman_tree))
        return -1;
    glist_destroy(&occurences);
    file_io_free(&file_io);
    return 0;
}
