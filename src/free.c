/*
** EPITECH PROJECT, 2021
** B-PSU-400-PAR-4-1-malloc-nicolas.allain
** File description:
** free
*/

#include "my_malloc.h"

void free(void *ptr)
{
    node_t *node = get_node(NULL, 0);

    for (; node != NULL; node = node->next) {
        if (ptr == node->memory) {
            node->free = true;
            get_node(node, 1);
            return;
        }
    }
    return;
}