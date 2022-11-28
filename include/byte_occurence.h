/*
** EPITECH PROJECT, 2022
** Huffman_coding
** File description:
** byte_occurence
*/

#ifndef BYTE_OCCURENCE_H_
#define BYTE_OCCURENCE_H_
#include "inttypes.h"

struct byte_occurence_s
{
    uint8_t byte;
    uint64_t occurence;
};

struct occ_array_s
{
    uint64_t capacity;
    uint64_t size;
    struct byte_occurence_s* data;
};

int init_occ_array(struct occ_array_s* array);
struct occ_array_s* create_occ_array(void);
void occ_array_add(uint8_t byte, struct occ_array_s* array);
void occ_pop_end(struct byte_occurence_s* array);

#endif /* !BYTE_OCCURENCE_H_ */
