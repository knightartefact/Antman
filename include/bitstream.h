/*
** EPITECH PROJECT, 2023
** huffman_coding
** File description:
** bitstream
*/

#ifndef BITSTREAM_H_
#define BITSTREAM_H_
#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>

#define MAX_BUFF_SIZE sizeof(uint8_t)*8

static const uint64_t DefaultReadBufSize = 256;

typedef struct bitstream_s bitstream_t;
typedef struct buffer_s buffer_t;

enum file_mode {
    FILE_READ,
    FILE_WRITE,
    UNKNOWN_MODE,

    ENUM_SIZE
};

struct buffer_s {
    uint8_t *data;
    uint64_t size;
    uint64_t pos;
    uint8_t bit_pos;
};

struct bitstream_s {
    FILE *file;
    buffer_t buffer;
    enum file_mode mode;
    uint64_t chunk_size;
};

bitstream_t *bitstream_create(char *filename, char *mode);
void bitstream_destroy(bitstream_t **stream);
int bitstream_read_file(bitstream_t *stream);
int bitstream_load_from_file(bitstream_t *stream, FILE *file);
int bitstream_write_bit(bitstream_t *stream, bool bit);
int bitstream_read_bit(bitstream_t *stream, uint8_t l_offset);
void bitstream_flush(bitstream_t *stream);

#endif /* !BITSTREAM_H_ */
