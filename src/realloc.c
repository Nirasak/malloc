/*
** EPITECH PROJECT, 2021
** B-PSU-400-PAR-4-1-malloc-nicolas.allain
** File description:
** realloc
*/

#include "my_malloc.h"

void *realloc(void *ptr, size_t size)
{
    node_t *node = get_node(NULL, 0);
    void *tmp_ptr = NULL;

    if (size <= 0) {
        free(ptr);
    }
    for (; node && node->memory != ptr; node = node->next);
    if (!ptr || !node) {
        return (malloc(size));
    } else {
        tmp_ptr = malloc(size);
        if (node->size >= size)
            memcpy(tmp_ptr, ptr, size);
        else
            memcpy(tmp_ptr, ptr, node->size);
        free(node->memory);
    }
    return (tmp_ptr);
}