/*
** EPITECH PROJECT, 2023
** GenericC-DS
** File description:
** generic_list
*/

#ifndef GENERIC_LIST_H_
#define GENERIC_LIST_H_
#include <stddef.h>
#include <stdbool.h>

typedef struct GNode_s GNode_t;
typedef struct GList_s GList_t;

struct GNode_s {
    void *data;
    GNode_t *next;
    GNode_t *prev;
};

struct GList_s {
    GNode_t *head;
    GNode_t *tail;
    size_t chunk_size;
    size_t size;
};

GNode_t* gnode_create(size_t chunk_size, void *data);
void gnode_destroy(GNode_t **node);
GList_t* glist_new(size_t chunk_size);
void glist_destroy(GList_t **list);
size_t glist_size(GList_t *list);
int glist_pushback(GList_t *list, void *elem);
void *glist_popback(GList_t *list);
void *glist_back(GList_t *list);
void *glist_popfront(GList_t *list);
void *glist_front(GList_t *list);
void glist_print(GList_t *list, void(*print_function)(const void *));
int glist_sort(GList_t *list, int(*comparator)(const void *, const void*));

#endif /* !GENERIC_LIST_H_ */
