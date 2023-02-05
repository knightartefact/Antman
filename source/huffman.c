/*
** EPITECH PROJECT, 2022
** Huffman_coding
** File description:
** main
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
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
    return huffman_compressor(av[1], av[2]);
}


