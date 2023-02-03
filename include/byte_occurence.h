/*
** EPITECH PROJECT, 2022
** Huffman_coding
** File description:
** byte_occurence
*/

#ifndef BYTE_OCCURENCE_H_
#define BYTE_OCCURENCE_H_
#include "inttypes.h"

typedef struct GList_s GList_t;

struct byte_occurence_s
{
    uint8_t byte;
    uint64_t occurence;
};

typedef struct byte_occurence_s byte_occurence_t;

void occurence_add(uint8_t byte, GList_t *occ_list);
void occurence_print(const void *data);
int occurence_comp(const void *lhs, const void *rhs);

#endif /* !BYTE_OCCURENCE_H_ */
