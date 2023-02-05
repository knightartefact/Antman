/*
** EPITECH PROJECT, 2023
** huffman_coding
** File description:
** bitstream
*/

#include <string.h>
#include <stdlib.h>
#include "bitstream.h"
#include "file_io.h"

static int bitstream_read_file(bitstream_t *stream)
{
    file_io_t* io = file_io_create();
    size_t file_size = file_io_get_size(stream->file);
    uint8_t *buffer = NULL;

    if (!io)
        return -1;
    buffer = file_io_read_file(stream->file);
    if (!buffer) {
        file_io_free(&io);
        return -1;
    }
    stream->buffer.data = buffer;
    stream->buffer.size = file_size;
    stream->buffer.pos = 0;
    file_io_free(&io);
    return 0;
}

static int bitstream_init(bitstream_t *stream, FILE *file, char *mode)
{
    int read_result = 0;

    stream->file = file;
    stream->buffer.pos = 0;
    stream->buffer.data = NULL;
    stream->chunk_size = sizeof(uint8_t);
    switch (*mode) {
        case 'w':
            stream->mode = FILE_WRITE;
            stream->buffer.data = malloc(stream->chunk_size);
            break;
        case 'r':
            stream->mode = FILE_READ;
            read_result = bitstream_read_file(stream);
            break;
        default:
            stream->mode = UNKNOWN_MODE;
            break;
    }
    if (read_result)
        return -1;
    return 0;
}

bitstream_t *bitstream_create(char *filename, char *mode)
{
    FILE *file = fopen(filename, mode);
    bitstream_t *bitstream = malloc(sizeof(bitstream_t));

    if (!file) {
        free(bitstream);
        perror(filename);
        return NULL;
    }
    if (!bitstream) {
        fclose(file);
        perror("Bitstream allocation");
        return NULL;
    }
    bitstream_init(bitstream, file, mode);
    return bitstream;
}

void bitstream_destroy(bitstream_t **stream)
{
    bitstream_flush(*stream);
    fclose((*stream)->file);
    if ((*stream)->buffer.data)
        free((*stream)->buffer.data);
    free(*stream);
}

int bitstream_write_bit(bitstream_t *stream, bool bit)
{
    if (stream->mode != FILE_WRITE) {
        return -1;
    }
    *(stream->buffer.data) <<= 1;
    *(stream->buffer.data) |= bit;
    stream->buffer.pos++;
    if (stream->buffer.pos == MAX_BUFF_SIZE) {
        fwrite(stream->buffer.data, stream->chunk_size, 1, stream->file);
        stream->buffer.pos = 0;
        *(stream->buffer.data) = 0;
    }
    return 0;
}

bool bitstream_read_bit(bitstream_t *stream)
{
    static int bit_pos = (sizeof(uint8_t) * 8) - 1;
    bool bit = 0;

    if (bit_pos < 0) {
        bit_pos = (sizeof(uint8_t) * 8) - 1;
        stream->buffer.pos++;
    }
    bit = (stream->buffer.data[stream->buffer.pos]) & (1 << bit_pos);
    bit_pos--;
    return bit;
}

void bitstream_flush(bitstream_t *stream)
{
    *(stream->buffer.data) <<= (MAX_BUFF_SIZE - stream->buffer.pos);
    fwrite(stream->buffer.data, stream->chunk_size, 1, stream->file);
    *(stream->buffer.data) = 0;
    stream->buffer.pos = 0;
}
