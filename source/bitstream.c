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

int bitstream_read_file(bitstream_t *stream)
{
    file_io_t *io = file_io_create();

    io->file_ptr = stream->file;
    file_io_read_file(io);

    if (!io->file_buffer)
        return -1;
    stream->buffer.data = calloc(sizeof(uint8_t), io->buf_size);
    if (!stream->buffer.data) {
        perror("Allocating bitstream buffer");
        return -1;
    }
    memmove(stream->buffer.data, io->file_buffer, sizeof(uint8_t) * io->buf_size);
    stream->buffer.size = io->buf_size;
    stream->buffer.pos = 0;
    stream->buffer.bit_pos = (uint8_t)(sizeof(uint8_t) * 8);
    io->file_ptr = NULL;
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
            break;
        default:
            stream->mode = UNKNOWN_MODE;
            break;
    }
    if (read_result || !stream->buffer.data)
        return -1;
    return 0;
}

bitstream_t *bitstream_create(char *filename, char *mode)
{
    bitstream_t *bitstream = malloc(sizeof(bitstream_t));
    FILE *file = NULL;

    if (!filename) {
        bitstream_init(bitstream, NULL, mode);
        return bitstream;
    }
    if (!bitstream) {
        fclose(file);
        perror("Bitstream allocation");
        return NULL;
    }
    file = fopen(filename, mode);
    if (!file) {
        free(bitstream);
        perror(filename);
        return NULL;
    }
    bitstream_init(bitstream, file, mode);
    return bitstream;
}

void bitstream_destroy(bitstream_t **stream)
{
    bitstream_flush(*stream);
    if ((*stream)->file)
        fclose((*stream)->file);
    if ((*stream)->buffer.data)
        free((*stream)->buffer.data);
    free(*stream);
}

int bitstream_load_from_file(bitstream_t *stream, FILE *file)
{
    if (stream->file)
        fclose(file);
    if (stream->buffer.data)
        free(stream->buffer.data);
    stream->file = file;
    stream->buffer.data = NULL;
    stream->buffer.bit_pos = stream->chunk_size;
    stream->buffer.pos = 0;
    stream->buffer.size = 0;
    return 0;
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

int bitstream_read_bit(bitstream_t *stream, uint8_t l_offset)
{
    bool bit = 0;

    if (stream->buffer.pos >= stream->buffer.size) {
        return -1;
    }
    if (stream->buffer.pos >= stream->buffer.size - 1 && stream->buffer.bit_pos == l_offset)
            return -1;
    if (stream->buffer.bit_pos == 0) {
        stream->buffer.bit_pos = (sizeof(uint8_t) * 8);
        stream->buffer.pos++;
    }
    bit = (stream->buffer.data[stream->buffer.pos]) & (1 << (stream->buffer.bit_pos - 1));
    stream->buffer.bit_pos--;
    return bit;
}

void bitstream_flush(bitstream_t *stream)
{
    *(stream->buffer.data) <<= (MAX_BUFF_SIZE - stream->buffer.pos);
    fwrite(stream->buffer.data, stream->chunk_size, 1, stream->file);
    *(stream->buffer.data) = 0;
    stream->buffer.pos = 0;
}
