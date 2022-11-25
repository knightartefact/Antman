/*
** EPITECH PROJECT, 2022
** Huffman_coding
** File description:
** main
*/
#include "file_io.h"

int main(int ac, char** av)
{
    struct file_io_s* file_io = create_file_io();

    if (!file_io || ac < 2)
    {
        return 1;
    }
    init_file_io(file_io);
    if (load_file(av[1], file_io))
    {
        return 1;
    }
    printf("%s", file_io->file_buffer);
    return 0;
}
