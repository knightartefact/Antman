/*
** EPITECH PROJECT, 2022
** Huffman_coding
** File description:
** main
*/
#include "file_io.h"
#include "huffman_tree.h"
#include "byte_occurence.h"
#include "huffman_node_list.h"
#include <unistd.h>

#define HEADER_ONLY
#include "generic_list.h"

void occurence_print(void *data)
{
    struct byte_occurence_s *occ = (struct byte_occurence_s *)data;
    char string[3] = "\\n";

    if ((char)occ->byte != '\n') {
        string[0] = (char)occ->byte;
        string[1] = 0;
        string[2] = 0;
    }
    printf("[%s] -> %ld\n", string, occ->occurence);
}

int main(int ac, char** av)
{
    struct file_io_s* file_io = NULL;
    file_io = file_io_create();

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
    // struct huffman_tree_s* huffman_tree = create_tree();
    // init_huffman_tree(huffman_tree);
    // struct occ_array_s* occurence_array = create_occ_array();
    // init_occ_array(occurence_array);

    for (int buf_i = 0; file_io->file_buffer[buf_i]; buf_i++)
    {
        occurence_add(file_io->file_buffer[buf_i], occurences);
    }
    glist_print(occurences, occurence_print);
    glist_destroy(&occurences);
    file_io_free(&file_io);

    // struct node_list_s* node_list = create_list();

    // for (uint64_t i = 0; i < occurence_array->size - 1; i++)
    // {
    //     struct huffman_node_s node;

    //     node.left = NULL;
    //     node.right = NULL;
    //     node.occurrence = occurence_array->data[i].occurence;
    //     node.value = occurence_array->data[i].byte;
    //     list_push_front(node_list, node);
    // }

    // list_print_data(node_list);
    return 0;
}
