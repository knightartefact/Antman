/*
** EPITECH PROJECT, 2023
** GenericC-DS
** File description:
** generic_list
*/

#ifndef GENERIC_LIST_H_
#define GENERIC_LIST_H_
#include <stddef.h>

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
void glist_print(GList_t *list, void(*print_function)(void *));

#ifdef HEADER_ONLY
    #include <stdlib.h>
    #include <string.h>
    #include <stdio.h>

    GNode_t *gnode_create(size_t chunk_size, void *data)
    {
        GNode_t *node = malloc(sizeof(GNode_t));

        if (!node) {
            printf("Couldn't allocate memory for new node\n");
            return NULL;
        }
        if (!data) {
            node->data = NULL;
            return node;
        }
        node->data = malloc(chunk_size);
        memmove(node->data, data, chunk_size);
        node->next = NULL;
        node->prev = NULL;
        return node;
    }

    void gnode_destroy(GNode_t **node)
    {
        free((*node)->data);
        free(*node);
    }

    GList_t* glist_new(size_t chunk_size)
    {
        GNode_t* head = gnode_create(chunk_size, NULL);
        GNode_t* tail = gnode_create(chunk_size, NULL);
        GList_t* list = malloc(sizeof(GList_t));

        if (!list) {
            free(head);
            free(tail);
            return NULL;
        }
        head->next = tail;
        tail->prev = head;
        list->head = head;
        list->tail = tail;
        list->size = 0;
        list->chunk_size = chunk_size;
        return list;
    }

    void glist_destroy(GList_t **list)
    {
        GNode_t *current_node = NULL;
        GNode_t *current_deleted_node = NULL;

        if (!list)
            return;
        current_node = (*list)->head->next;
        while (current_node && current_node != (*list)->tail) {
            current_deleted_node = current_node;
            current_node = current_node->next;
            gnode_destroy(&current_deleted_node);
        }
        free((*list)->head);
        free((*list)->tail);
        free(*list);
    }

    size_t glist_size(GList_t *list)
    {
        return list->size;
    }

    int glist_pushback(GList_t *list, void *elem)
    {
        GNode_t *new_node = gnode_create(list->chunk_size, elem);

        new_node->prev = list->tail->prev;
        list->tail->prev->next = new_node;
        list->tail->prev = new_node;
        list->size++;
        return 0;
    }

    void *glist_popback(GList_t *list)
    {
        void *data = NULL;
        GNode_t *last_node = NULL;

        if (!list->size) {
            return NULL;
        }
        if (list->size == 1) {
            last_node = list->tail->prev;
            data = last_node->data;
            list->head->next = list->tail;
            list->tail->prev = list->head;
            list->size--;
            return data;
        }
        last_node = list->tail->prev;
        data = last_node->data;
        last_node->prev->next = list->tail;
        list->tail->prev = last_node->prev;
        list->size--;
        return data;
    }

    void *glist_back(GList_t *list)
    {
        return list->tail->prev->data;
    }

    void *glist_front(GList_t *list)
    {
        return list->head->next->data;
    }

    void *glist_popfront(GList_t *list)
    {
        void *data = NULL;
        GNode_t *first_node = NULL;

        if (!list->size) {
            return NULL;
        }
        if (list->size == 1) {
            first_node = list->head->next;
            data = first_node->data;
            list->head->next = list->tail;
            list->tail->prev = list->head;
            list->size--;
            return data;
        }
        first_node = list->head->next;
        data = first_node->data;
        first_node->next->prev = list->head;
        list->head->next = first_node->next;
        list->size--;
        return data;
    }

    void glist_print(GList_t *list, void (*print_function)(void *))
    {
        GNode_t *current = NULL;

        if (!list)
            return;
        current = list->head->next;
        while (current && current != list->tail) {
            print_function(current->data);
            current = current->next;
        }
    }
    #endif //HEADER_ONLY

#endif /* !GENERIC_LIST_H_ */
