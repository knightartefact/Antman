/*
** EPITECH PROJECT, 2023
** Antman
** File description:
** stack
*/

#ifndef STACK_H_
#define STACK_H_
#include <stddef.h>
#include <inttypes.h>
#include <stdbool.h>
#include "huffman_node.h"

typedef struct stack_s stack_t;

struct stack_s {
    size_t top;
    size_t size;
    huff_node_t **data;
};

stack_t *stack_new(int size);
void stack_destroy(stack_t **stack);
void stack_push(stack_t *stack, huff_node_t *value);
huff_node_t *stack_pop(stack_t *stack);
bool stack_is_empty(stack_t *stack);

#endif /* !STACK_H_ */
