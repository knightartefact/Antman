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
#include "generic_list.h"

void occurence_add(uint8_t byte, GList_t *occ_list)
{
    bool occurence_exists = false;
    GNode_t *current = NULL;

    if (!occ_list)
        return;
    current = occ_list->head->next;
    while (current && current != occ_list->tail)
    {
        if (current->data == NULL)
            break;
        byte_occurence_t *current_data = (byte_occurence_t *)(current->data);
        if (current_data->byte == byte)
        {
            current_data->occurence += 1;
            occurence_exists = true;
            break;
        }
        current = current->next;
    }
    if(!occurence_exists)
    {
        byte_occurence_t new_data = {.byte = byte, .occurence = 1};
        glist_pushback(occ_list, &new_data);
    }
}
