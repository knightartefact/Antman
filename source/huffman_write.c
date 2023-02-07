/*
** EPITECH PROJECT, 2023
** huffman_coding
** File description:
** huffman_write
*/

#include <inttypes.h>
#include <string.h>
#include "huffman_write.h"
#include "pair.h"

static char *huffman_get_code(uint8_t value, GList_t *codes)
{
    for (GNode_t *node = codes->head->next; node  && node != codes->tail; node = node->next) {
        pair_t *data = (pair_t *)node->data;
        if (!data)
            return NULL;
        if (data->value == value)
            return data->compressed;
    }
    return NULL;
}

static void _huffman_generate_file_tree_rec(huff_node_t *root, FILE *output_file)
{
    if (!root)
        return;
    _huffman_generate_file_tree_rec(root->right, output_file);
    _huffman_generate_file_tree_rec(root->left, output_file);
    if (huff_node_is_leaf(root)) {
        uint8_t one = '1';
        fwrite(&one, sizeof(uint8_t), 1, output_file);
        fwrite(&root->value, sizeof(uint8_t), 1, output_file);
    } else {
        uint8_t zero = '0';
        fwrite(&zero, sizeof(uint8_t), 1, output_file);
    }
}

static file_io_t *huffman_generate_file_tree(huff_tree_t *tree)
{
    char *temp_file_name = "temp_header.temp";
    FILE *temp_file = fopen(temp_file_name, "wb");
    file_io_t *io = file_io_create(NULL, "rb");

    if (!temp_file) {
        perror(temp_file_name);
        return NULL;
    }
    if (!io)
        return NULL;
    _huffman_generate_file_tree_rec(tree->root, temp_file);
    fclose(temp_file);
    if (file_io_load_file(temp_file_name, "rb", io) == -1)
        return NULL;
    return io;
}

int huffman_write_file_header(bitstream_t *stream, GList_t *codes, file_io_t *input, huff_tree_t *tree)
{
    uint8_t* last_code = (uint8_t *)huffman_get_code(input->file_buffer[input->buf_size - 1], codes);
    uint8_t last_bit_pos = 0;
    size_t header_content_size = 0;

    if (!last_code)
        return -1;
    last_bit_pos = (uint8_t)strlen((char *)last_code);

    file_io_t *header_tree = huffman_generate_file_tree(tree);
    if (!header_tree)
        return -1;
    header_content_size = header_tree->buf_size + (sizeof(uint8_t));
    fwrite(&input->buf_size, sizeof(size_t), 1, stream->file);
    fwrite(&header_content_size, sizeof(size_t), 1, stream->file);
    fwrite(&last_bit_pos, sizeof(uint8_t), 1, stream->file);
    fwrite(header_tree->file_buffer, sizeof(uint8_t), header_tree->buf_size, stream->file);
    file_io_free(&header_tree);
    return 0;
}

int huffman_write_file(char *filename, GList_t *codes, file_io_t *input, huff_tree_t *tree)
{
    bitstream_t *stream = bitstream_create(filename, "wb");

    if (!stream)
        return -1;
    bitstream_read_file(stream);
    huffman_write_file_header(stream, codes, input, tree);
    for (size_t index = 0; input->file_buffer[index]; index++) {
        char *compressed = huffman_get_code(input->file_buffer[index], codes);

        for (size_t i = 0; i < strlen(compressed); i++)  {
            bitstream_write_bit(stream, compressed[i] == '1' ? 1 : 0);
        }
    }
    bitstream_flush(stream);
    bitstream_destroy(&stream);
    return 0;
}

