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

typedef struct bitstream_s bitstream_t;

enum file_mode {
    FILE_READ,
    FILE_WRITE
};

struct bitstream_s {
    FILE *file;
    uint64_t buffer;
    short bit_pos;
    enum file_mode mode;
    uint64_t chunk_size;
};

bitstream_t *bitstream_create(char *filename, char *mode);
void bitstream_destroy(bitstream_t **stream);
int bitstream_put_bit(bitstream_t *stream, bool bit);
void bitstream_flush(bitstream_t *stream);

#endif /* !BITSTREAM_H_ */
