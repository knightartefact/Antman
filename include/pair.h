/*
** EPITECH PROJECT, 2023
** huffman_coding
** File description:
** pair
*/

#ifndef PAIR_H_
#define PAIR_H_
#include <inttypes.h>

typedef struct pair_s pair_t;

struct pair_s {
    uint8_t value;
    char *compressed;
};

void pair_print(const void *pair);
void pair_destroy(void *pair);

#endif /* !PAIR_H_ */
