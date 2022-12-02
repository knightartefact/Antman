/*
** EPITECH PROJECT, 2022
** Huffman_coding
** File description:
** huffman_node_list
*/

#include "huffman_node_list.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

struct node_list_s* create_list(void)
{
    struct node_list_s* list = malloc(sizeof(struct node_list_s));

    if (!list)
    {
        printf("Couldn't create list\n");
        return NULL;
    }
    list->count = 0;
    list->head = NULL;
    list->tail = NULL;

    return list;
}

struct list_node_s* list_create_node(void)
{
    struct list_node_s* node = malloc(sizeof(struct list_node_s));

    if (!node)
    {
        printf("Couldn't allocate new node when adding to list\n");
        return NULL;
    }
    list_init_node(node);
    return node;
}

void list_init_node(struct list_node_s* node)
{
    node->data = malloc(sizeof(struct huffman_node_s));
    node->next = NULL;
    node->prev = NULL;
}

void list_push_back(struct node_list_s* list, struct huffman_node_s new_node)
{
    struct list_node_s* new = list_create_node();
    struct list_node_s* current = list->head;

    if (!new)
    {
        return;
    }
    *new->data = new_node;
    if (!list->head)
    {
        list->head = new;
        return;
    }
    while (current->next)
    {
        current = current->next;
    }
    current = new;
}

void list_push_front(struct node_list_s* list, struct huffman_node_s new_node)
{
    struct list_node_s* new = list_create_node();

    if (!new)
    {
        return;
    }
    *new->data = new_node;
    if (!list->head) {
        list->head = new;
    }
    else {
        new->next = list->head->next;
        list->head = new;
    }
}

struct huffman_node_s* list_pop_back(struct node_list_s* list)
{
    list = list;
    return NULL;
}

struct huffman_node_s* list_pop_front(struct node_list_s* list)
{
    struct huffman_node_s* data = NULL;

    data = list->head->data;
    list->head = list->head->next;
    return data;
}

void list_print_data(struct node_list_s* list)
{
    struct list_node_s* current = list->head;

    while (current)
    {
        printf("Node\n");
        //printf("%c : %ld\n", current->data->value, current->data->occurrence);
        current = current->next;
    }
}

void list_sort(struct node_list_s* list)
{
    list = list;
}

