/*
** EPITECH PROJECT, 2022
** Huffman_coding
** File description:
** file_io
*/

#ifndef FILE_IO_H_
#define FILE_IO_H_
#include <stdio.h>
#include <inttypes.h>

typedef struct file_io_s file_io_t;

struct file_io_s
{
    FILE* file_ptr;
    char *filepath;
    uint8_t* file_buffer;
    size_t buf_size;
};

file_io_t* file_io_create(void);
FILE* file_io_open_file(char *filepath, char *modes);
int file_io_get_size(FILE* file);
int file_io_read_file(file_io_t* file);
void file_io_init(file_io_t* file_io);
int file_io_load_file(char* filepath, char *modes, file_io_t* file_io_out);
void file_io_free(file_io_t **file_io);

#endif /* !FILE_IO_H_ */
