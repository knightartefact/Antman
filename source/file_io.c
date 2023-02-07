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

int file_io_read_file(file_io_t* file)
{
    size_t bytes_read = 0;
    size_t buf_read_size = 64;
    size_t buf_size = 0;
    size_t buf_max_size = buf_read_size;
    uint8_t* buffer = malloc(sizeof(uint8_t) * (buf_read_size + 1));

    if (!buffer)
        return -1;
    do {
        bytes_read = fread(buffer + buf_size, sizeof(uint8_t), buf_read_size, file->file_ptr);
        buf_size += bytes_read;

        if (buf_size >= buf_max_size - 1) {
            uint8_t *temp = realloc(buffer, (buf_max_size * 2));
            if (!temp)
                return -1;
            buffer = temp;
            buf_max_size = buf_max_size * 2;
        }

    } while (bytes_read != 0);

    buffer[buf_size] = 0;
    file->buf_size = buf_size;
    file->file_buffer = buffer;
    return buf_size;
}

file_io_t* file_io_create()
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
    file_io->buf_size = 0;
}

int file_io_load_file(char* filepath, char *modes, file_io_t* io_out)
{
    if (io_out->file_buffer)
        free(io_out->file_buffer);
    if (io_out->file_ptr)
        fclose(io_out->file_ptr);
    if (io_out->filepath)
        free(io_out->filepath);
    file_io_init(io_out);
    io_out->filepath = strdup(filepath);
    io_out->file_ptr = file_io_open_file(filepath, modes);
    if (!io_out->file_ptr || !io_out->filepath)
        return -1;
    return 0;
}

void file_io_free(file_io_t **file_io)
{
    if ((*file_io)->file_ptr)
        fclose((*file_io)->file_ptr);
    if ((*file_io)->filepath)
        free((*file_io)->filepath);
    if ((*file_io)->file_buffer)
        free((*file_io)->file_buffer);
    free(*file_io);
}
