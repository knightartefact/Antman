/*
** EPITECH PROJECT, 2023
** huffman_coding
** File description:
** huffman_write
*/

#include <inttypes.h>
#include "huffman_write.h"
#include "pair.h"

char *huffman_get_code(uint8_t value, GList_t *codes)
{
    for (GNode_t *node = codes->head->next; node  && node != codes->tail; node = node->next) {
        pair_t *data = (uint8_t *)node->data;
        if (!data)
            continue;
        if (data->value == value)
            return data->compressed;
    }
    return NULL;
}

void huffman_write_byte(FILE *file, char *byte)
{
    int MAX_BYTE_SIZE = 64;
    static uint64_t writable = 0;

    for (int i = 0; i < MAX_BYTE_SIZE; i++) {

    }
}

int huffman_write_file(char *filename, GList_t *codes, file_io_t input)
{
    uint8_t writeable_byte = 0;

    for (size_t index = 0; input.file_buffer[index]; index++) {
        char *compressed = huffman_get_code(input.file_buffer[index], codes);

    }
    return 0;
}
