/*
** EPITECH PROJECT, 2023
** Antman
** File description:
** huffman_read
*/

#include <stdlib.h>
#include "huffman_read.h"
#include "huffman_tree.h"
#include "stack.h"

int huffman_read_file(char *filename)
{
    bitstream_t *stream = bitstream_create(filename, "rb");
    f_header_data_t data = {0};
    huff_tree_t *tree;
    int read_bytes = 0;

    if (!stream)
        return -1;
    if ((read_bytes = huffman_read_header(filename, &data)) == -1) {
        if (data.raw_tree)
            free(data.raw_tree);
        return -1;
    }
    stack_t *stack = stack_new(1024);
    tree = huff_tree_create();
    stream->buffer.pos += read_bytes;

    for (size_t i = 0; i < data.header_size; i++) {
        if (data.raw_tree[i] == '1') {
            huff_node_t *node = huff_node_create(1, data.raw_tree[++i], NULL, NULL);
            stack_push(stack, node);
        }
        if(data.raw_tree[i] == '0') {
            if (stack->size == 1) {
                break;
            }
            huff_node_t *lvalue = stack_pop(stack);
            huff_node_t *rvalue = stack_pop(stack);
            huff_node_t *parent = huff_node_create(1, 0, lvalue, rvalue);
            stack_push(stack, parent);
        }
    }
    tree->root = stack->data[0];
    huff_tree_print(tree);
    int bit = 0;
    huff_node_t *current_node = tree->root;
    while ((bit = bitstream_read_bit(stream, data.last_bit_off)) != -1)
    {
        if (bit == 1)
            current_node = current_node->right;
        if (bit == 0)
            current_node = current_node->left;
        if (huff_node_is_leaf(current_node)) {
            // printf("%c", current_node->value);
            current_node = tree->root;
        }
    }
    // printf("\n");
    return 0;
}

int huffman_read_header(char *filename, f_header_data_t *data)
{
    FILE *file = fopen(filename, "rb");
    int read_bytes = 0;

    if (!file) {
        perror(filename);
        return -1;
    }
    read_bytes += sizeof(size_t) * fread(&data->original_size, sizeof(size_t), 1, file);
    read_bytes += sizeof(size_t) * fread(&data->header_size, sizeof(size_t), 1, file);
    read_bytes += fread(&data->last_bit_off, sizeof(uint8_t), 1, file);

    data->raw_tree = calloc(data->header_size + 1, sizeof(uint8_t));
    if (!data->raw_tree) {
        perror("Error allocating header raw tree");
        return -1;
    }
    read_bytes += fread(data->raw_tree, sizeof(uint8_t), data->header_size - 1, file);
    fclose(file);
    return read_bytes;
}
