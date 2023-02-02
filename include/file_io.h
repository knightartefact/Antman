/*
** EPITECH PROJECT, 2022
** Huffman_coding
** File description:
** file_io
*/

#ifndef FILE_IO_H_
#define FILE_IO_H_
#include <stdio.h>

struct file_io_s
{
    FILE* file_ptr;
    char *filepath;
    char* file_buffer;
};
typedef struct file_io_s file_io_t;

FILE* file_io_open_file(char *filepath, char *modes);
int file_io_get_size(FILE* file);
char *file_io_read_file(FILE* file);
file_io_t* file_io_create(void);
void file_io_init(file_io_t* file_io);
int file_io_load_file(char* filepath, file_io_t* file_io_out);
void file_io_free(file_io_t **file_io);

#endif /* !FILE_IO_H_ */
