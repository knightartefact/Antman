/*
** EPITECH PROJECT, 2022
** Huffman_coding
** File description:
** file_io
*/

#ifndef FILE_IO_H_
#define FILE_IO_H_
#include "stdio.h"

struct file_io_s
{
    FILE* file_ptr;
    char *filepath;
    char* file_buffer;
};

FILE* open_file(char *filepath, char *modes);
int get_file_size(FILE* file);
char *read_file(FILE* file);
struct file_io_s* create_file_io(void);
void init_file_io(struct file_io_s* file_io);
int load_file(char* filepath, struct file_io_s* file_io_out);

#endif /* !FILE_IO_H_ */
