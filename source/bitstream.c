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
        return NULL;
    }
    if (!bitstream) {
        fclose(file);
        perror("Bitstream allocation");
        return NULL;
    }
    bitstream->file = file;
    bitstream->bit_pos = 0;
    bitstream->buffer = 0;
    bitstream->chunk_size = sizeof(uint8_t);
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
    return bitstream;
}

void bitstream_destroy(bitstream_t **stream)
{
    fclose((*stream)->file);
    free(*stream);
}

int bitstream_put_bit(bitstream_t *stream, bool bit)
{
    if (stream->mode != FILE_WRITE) {
        return -1;
    }
    stream->buffer <<= 1;
    stream->buffer |= bit;
    stream->bit_pos++;
    if (stream->bit_pos == MAX_BUFF_SIZE) {
        fwrite(&stream->buffer, stream->chunk_size, 1, stream->file);
        stream->bit_pos = 0;
        stream->buffer = 0;
    }
    return 0;
}

void bitstream_flush(bitstream_t *stream)
{
    stream->buffer <<= (MAX_BUFF_SIZE - stream->bit_pos);
    fwrite(&stream->buffer, stream->chunk_size, 1, stream->file);
    stream->buffer = 0;
    stream->bit_pos = 0;
}
