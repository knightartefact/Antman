/*
** EPITECH PROJECT, 2023
** huffman_coding
** File description:
** pair
*/

#include <stdio.h>
#include <stdlib.h>
#include "pair.h"

void pair_print(const void *pair)
{
    pair_t *cast_pair = (pair_t *)pair;
    char string[3] = "\\n";

    if (cast_pair->value != '\n') {
        string[0] = cast_pair->value;
        string[1] = 0;
    }
    printf("pair | <%s, %s>\n", string, cast_pair->compressed);
}

void pair_destroy(void *pair)
{
    pair_t *cast_pair = (pair_t *)pair;
    free(cast_pair->compressed);
}
