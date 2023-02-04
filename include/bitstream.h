/*
** EPITECH PROJECT, 2023
** huffman_coding
** File description:
** bitstream
*/

#ifndef BITSTREAM_H_
#define BITSTREAM_H_
#include "inttypes.h"
#include <stdio.h>

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
};

bitstream_t *bitstream_create(char *filename, char *mode);

#endif /* !BITSTREAM_H_ */
