/*
** EPITECH PROJECT, 2022
** Huffman_coding
** File description:
** byte_occurence
*/

#include "byte_occurence.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int init_occ_array(struct occ_array_s* array)
{
    int capacity = 8;
    array->data = malloc(sizeof(struct byte_occurence_s) * capacity);
    array->capacity = capacity;
    array->size = 0;
    return 0;
}

struct occ_array_s* create_occ_array(void)
{
    struct occ_array_s* array = malloc(sizeof(struct occ_array_s));

    if (!array)
    {
        printf("Couldn't allocate occurence node array memory\n");
        return NULL;
    }
    return array;
}

void occ_array_add(uint8_t byte, struct occ_array_s* array)
{
    bool occurence_exists = false;

    if (array->size >= array->capacity)
    {
        array->capacity *= 2;
        array->data = realloc(array->data, array->capacity * sizeof(struct byte_occurence_s));
    }
    for (uint64_t i = 0; i < array->size; i++)
    {
        if (array->data[i].byte == byte)
        {
            array->data[i].occurence += 1;
            occurence_exists = true;
            break;
        }
    }
    if(!occurence_exists)
    {
        array->data[array->size] = (struct byte_occurence_s){byte, 1};
        array->size += 1;
    }
}

void occ_array_pop(struct occ_array_s* array)
{
    array->size--;
}

void free_occ_array(struct occ_array_s *array)
{
    free (array->data);
}
