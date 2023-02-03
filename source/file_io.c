/*
** EPITECH PROJECT, 2022
** Huffman_coding
** File description:
** file_io
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "file_io.h"

FILE* file_io_open_file(char *filepath, char *modes)
{
    FILE* file_ptr = NULL;

    file_ptr = fopen(filepath, modes);
    if (!file_ptr)
    {
        perror(filepath);
        return NULL;
    }
    return file_ptr;
}

int file_io_get_size(FILE* file)
{
    int size = 0;

    fseek(file, 0, SEEK_END);
    size = ftell(file);
    fseek(file, 0, SEEK_SET);
    return size;
}

char *file_io_read_file(FILE* file)
{
    int file_size = file_io_get_size(file);
    char* buffer = malloc(sizeof(char) * (file_size + 1));
    int bytes_read = 0;

    if (!buffer)
    {
        perror("Couldn't allocate file buffer memory");
        return NULL;
    }
    bytes_read = fread(buffer, sizeof(char), file_size, file);
    if (bytes_read != file_size)
    {
        perror("Couldn't read file in it's entirity");
    }
    buffer[file_size] = 0;
    return buffer;
}

file_io_t* file_io_create(void)
{
    file_io_t* file_io = malloc(sizeof(file_io_t));

    if (!file_io)
    {
        perror("Couldn't allocate file_io memory");
        return NULL;
    }
    file_io_init(file_io);
    return file_io;
}

void file_io_init(file_io_t* file_io)
{
    file_io->file_buffer = NULL;
    file_io->file_ptr = NULL;
    file_io->filepath = NULL;
}

int file_io_load_file(char* filepath, file_io_t* file_io_out)
{
    file_io_out->filepath = strdup(filepath);
    file_io_out->file_ptr = file_io_open_file(filepath, "r");
    if (!file_io_out->file_ptr || !file_io_out->filepath)
    {
        return -1;
    }
    file_io_out->file_buffer = file_io_read_file(file_io_out->file_ptr);
    if (!file_io_out->file_buffer)
    {
        fclose(file_io_out->file_ptr);
        return -1;
    }
    fclose(file_io_out->file_ptr);
    return 0;
}

void file_io_free(file_io_t **file_io)
{
    free((*file_io)->filepath);
    free((*file_io)->file_buffer);
    free(*file_io);
}
