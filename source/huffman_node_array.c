/*
** EPITECH PROJECT, 2022
** Huffman_coding
** File description:
** huffman_node_array
*/

#include "huffman_node_array.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

int init_node_array(struct huffman_node_array_s* array)
{
    int size = 8;
    array->data = malloc(sizeof(struct huffman_node_s) * size);
    array->capacity = size;
    array->size = 0;
    return 0;
}

struct huffman_node_array_s* create_node_array(void)
{
    struct huffman_node_array_s* array = malloc(sizeof(struct huffman_node_array_s));

    if (!array)
    {
        printf("Couldn't allocate huffman node array memory\n");
        return NULL;
    }
    return array;
}

void node_array_add(struct huffman_node_s new_node, struct huffman_node_array_s* array)
{
    if (array->size >= array->capacity)
    {
        array->capacity *= 2;
        array->data = realloc(array->data, array->size * sizeof(struct huffman_node_s));
    }
    array->data[array->size] = new_node;
    array->size += 1;
}

void node_array_pop(struct huffman_node_array_s* array, int index)
{
    if ((uint64_t)index > array->size)
    {
        printf("Node array index out of range\n");
        return;
    }
    for (uint64_t i = index; i < array->size - 1; i++)
    {
        array->data[i] = array->data[i + 1];
    }
    array->size--;
}
