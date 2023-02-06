/*
** EPITECH PROJECT, 2023
** Antman
** File description:
** stack
*/

#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

stack_t *stack_new(int size)
{
    stack_t *stack = malloc(sizeof(stack_t));

    if (!stack) {
        perror("Error allocating stack");
        return NULL;
    }
    stack->size = size;
    stack->top = 0;
    stack->data = malloc(size * sizeof(huff_node_t *));
    if (!stack->data) {
        perror("Error allocating stack data");
        free(stack);
        return NULL;
    }
    return stack;
}

void stack_destroy(stack_t **stack)
{
    for (size_t i = 0; i < (*stack)->top; i++) {
        free((*stack)->data[i]);
    }
    if ((*stack)->data)
        free((*stack)->data);
    free(*stack);
}

void stack_push(stack_t *stack, huff_node_t *value)
{
    // huff_node_t **temp_array = NULL;

    // if (stack->top >= stack->size) {
    //     temp_array = realloc(stack->data, (stack->size * 2 * sizeof(huff_node_t *)));
    // }
    // if (!temp_array) {
    //     perror("Error reallocating stack data");
    //     return;
    // }
    //stack->size *= 2;
    stack->data[stack->top] = value;
    stack->top++;
}

huff_node_t *stack_pop(stack_t *stack)
{
    if (stack->top != 0)
        stack->top--;
    huff_node_t *node = stack->data[stack->top];
    // if(stack->top < stack->size) {
    //     huff_node_t **temp_array = realloc(stack->data, (stack->size / 2) * sizeof(huff_node_t *));
    //     if (!temp_array) {
    //         return NULL;
    //     }
    //     stack->data = temp_array;
    // }
    return node;
}

bool stack_is_empty(stack_t *stack)
{
    return (!stack->size);
}
