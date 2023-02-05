/*
** EPITECH PROJECT, 2023
** huffman_coding
** File description:
** huffman_write
*/

#include <inttypes.h>
#include <string.h>
#include "huffman_write.h"
#include "bitstream.h"
#include "pair.h"

static char *huffman_get_code(uint8_t value, GList_t *codes)
{
    for (GNode_t *node = codes->head->next; node  && node != codes->tail; node = node->next) {
        pair_t *data = (pair_t *)node->data;
        if (!data)
            continue;
        if (data->value == value)
            return data->compressed;
    }
    return NULL;
}

int huffman_write_file(char *filename, GList_t *codes, file_io_t *input)
{
    bitstream_t *stream = bitstream_create(filename, "wb");

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

int huffman_write_file_header(FILE *file, GList_t *codes)
{
    size_t code_list_size = codes->size;

    return 0;
}
