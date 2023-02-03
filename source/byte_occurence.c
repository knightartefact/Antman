/*
** EPITECH PROJECT, 2022
** Huffman_coding
** File description:
** byte_occurence
*/

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "byte_occurence.h"
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

void occurence_print(const void *data)
{
    struct byte_occurence_s *occ = (struct byte_occurence_s *)data;
    char string[3] = "\\n";

    if ((char)occ->byte != '\n') {
        string[0] = (char)occ->byte;
        string[1] = 0;
        string[2] = 0;
    }
    printf("[%s] -> %ld\n", string, occ->occurence);
}

int occurence_comp(const void *lhs, const void *rhs)
{
    byte_occurence_t *occ_lhs = (byte_occurence_t *)lhs;
    byte_occurence_t *occ_rhs = (byte_occurence_t *)rhs;
    int result = occ_lhs->occurence - occ_rhs->occurence;
    return result;
}
