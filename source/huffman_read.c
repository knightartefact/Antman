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

int huffman_read_file(bitstream_t *stream, huff_tree_t *tree, uint8_t l_offset, FILE *out)
{
    int bit = 0;
    huff_node_t *current_node = tree->root;

    if (bitstream_read_file(stream) == -1)
        return -1;
    while ((bit = bitstream_read_bit(stream, l_offset)) != -1)
    {
        if (bit == 1) {
            current_node = current_node->right;
        }
        if (bit == 0) {
            current_node = current_node->left;
        }
        if (huff_node_is_leaf(current_node)) {
            fwrite(&current_node->value, sizeof(uint8_t), 1, out);
            current_node = tree->root;
        }
    }
    return 0;
}

int huffman_read_header(FILE *file, f_header_data_t *data)
{
    int read_bytes = 0;

    read_bytes += sizeof(size_t) * fread(&data->original_size, sizeof(size_t), 1, file);
    read_bytes += sizeof(size_t) * fread(&data->header_size, sizeof(size_t), 1, file);
    read_bytes += fread(&data->last_bit_off, sizeof(uint8_t), 1, file);

    data->raw_tree = calloc(data->header_size + 1, sizeof(uint8_t));
    if (!data->raw_tree) {
        perror("Error allocating header raw tree");
        return -1;
    }
    read_bytes += fread(data->raw_tree, sizeof(uint8_t), data->header_size - 1, file);
    return read_bytes;
}

int huffman_rebuild_tree(f_header_data_t *data, huff_tree_t *tree)
{
    stack_t *stack = stack_new(1024);

    for (size_t i = 0; i < data->header_size - 1; i++) {
        if (data->raw_tree[i] == '1') {
            i++;
            huff_node_t *node = huff_node_create(1, data->raw_tree[i], NULL, NULL);
            if (!node)
                return -1;
            stack_push(stack, node);
            continue;
        }
        if(data->raw_tree[i] == '0') {
            if (stack->top == 0) {
                break;
            }
            huff_node_t *lvalue = stack_pop(stack);
            huff_node_t *rvalue = stack_pop(stack);
            huff_node_t *parent = huff_node_create(1, 0, lvalue, rvalue);
            if (!parent || !lvalue || !rvalue)
                return -1;
            stack_push(stack, parent);
            continue;
        }
    }
    if (stack->top > 0) {
        fprintf(stderr, "Error: stack is not of size 1, after rebuilding tree\n");
        return -1;
    }
    if (!stack->data[0]) {
        fprintf(stderr, "Error: root node is not allocated\n");
        return -1;
    }
    tree->root = stack->data[0];
    return 0;
}
