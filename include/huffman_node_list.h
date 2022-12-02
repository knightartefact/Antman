/*
** EPITECH PROJECT, 2022
** Huffman_coding
** File description:
** huffman_node_list
*/

#ifndef HUFFMAN_NODE_LIST_H_
#define HUFFMAN_NODE_LIST_H_

#include "huffman_node.h"
#include <stddef.h>

struct list_node_s
{
    struct huffman_node_s *data;
    struct list_node_s* next;
    struct list_node_s* prev;
};

struct node_list_s
{
    struct list_node_s* head;
    struct list_node_s* tail;
    size_t count;
};

struct node_list_s* create_list();
struct list_node_s* list_create_node(void);
void list_init_node(struct list_node_s* head);
void list_push_back(struct node_list_s* list, struct huffman_node_s new_node);
void list_push_front(struct node_list_s* list, struct huffman_node_s new_node);
struct huffman_node_s* list_pop_back(struct node_list_s* list);
struct huffman_node_s* list_pop_front(struct node_list_s* list);
void list_sort(struct node_list_s* list);
void list_print_data(struct node_list_s* list);
void list_sort(struct node_list_s* list);

#endif /* !HUFFMAN_NODE_LIST_H_ */
