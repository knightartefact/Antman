/*
** EPITECH PROJECT, 2023
** huffman_coding
** File description:
** bitstream
*/

#include <string.h>
#include <stdlib.h>
#include "bitstream.h"

bitstream_t *bitstream_create(char *filename, char *mode)
{
    FILE *file = fopen(filename, mode);
    bitstream_t *bitstream = malloc(sizeof(bitstream_t));
    if (!file) {
        perror(filename);
        return -1;
    }
    if (!bitstream) {
        fclose(file);
        perror("Bitstream allocation");
        return -1;
    }
    bitstream->file = file;
    bitstream->bit_pos = 0;
    bitstream->buffer = 0;
    switch (*mode) {
    case 'w':
        bitstream->mode = FILE_WRITE;
        break;
    case 'r':
        bitstream->mode = FILE_READ;
        break;
    default:
        break;
    }
    return NULL;
}
