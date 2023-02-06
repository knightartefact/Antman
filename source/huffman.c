/*
** EPITECH PROJECT, 2022
** Huffman_coding
** File description:
** main
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "huffman.h"
#include "file_io.h"

#include "bitstream.h"

int main(int ac, char** av)
{
    if (ac < 3) {
        // Here we should launch the -h function;
        printf("Not enough arguments\n");
        return -1;
    }
    if (strcmp(av[1], "-c") == 0)
        return huffman_compressor(av[2], av[3]);
    if (strcmp(av[1], "-d") == 0)
        return huffman_decompressor(av[2], av[3]);
}


