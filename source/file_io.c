/*
** EPITECH PROJECT, 2022
** Huffman_coding
** File description:
** file_io
*/

#include "file_io.h"
#include "stdlib.h"
#include "string.h"

FILE* open_file(char *filepath, char *modes)
{
    FILE* file_ptr = NULL;

    file_ptr = fopen(filepath, modes);
    if (!file_ptr)
    {
        printf("Couldn't open file\n");
        return NULL;
    }
    return file_ptr;
}

int get_file_size(FILE* file)
{
    int size = 0;

    fseek(file, 0, SEEK_END);
    size = ftell(file);
    fseek(file, 0, SEEK_SET);
    return size;
}

char *read_file(FILE* file)
{
    int file_size = get_file_size(file);
    char* buffer = malloc(sizeof(char) * (file_size + 1));
    int bytes_read = 0;

    if (!buffer)
    {
        printf("Couldn't allocate file buffer memory\n");
        return NULL;
    }
    bytes_read = fread(buffer, sizeof(char), file_size, file);
    if (bytes_read != file_size)
    {
        printf("Couldn't read file in it's entirity\n");
    }
    return buffer;
}

struct file_io_s* create_file_io(void)
{
    struct file_io_s* file_io = malloc(sizeof(struct file_io_s*));

    if (!file_io)
    {
        printf("Couldn't allocate file_io memory\n");
        return NULL;
    }
    return file_io;
}

void init_file_io(struct file_io_s* file_io)
{
    file_io->file_buffer = NULL;
    file_io->file_ptr = NULL;
    file_io->filepath = NULL;
}

int load_file(char* filepath, struct file_io_s* file_io_out)
{
    file_io_out->filepath = strdup(filepath);
    file_io_out->file_ptr = open_file(filepath, "r");
    if (!file_io_out->file_ptr || !file_io_out->filepath)
    {
        return -1;
    }
    file_io_out->file_buffer = read_file(file_io_out->file_ptr);
    if (!file_io_out->file_buffer)
    {
        return -1;
    }
    return 0;
}
