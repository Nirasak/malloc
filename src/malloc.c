/*
** EPITECH PROJECT, 2021
** B-PSU-400-PAR-4-1-malloc-nicolas.allain
** File description:
** malloc
*/

#include "my_malloc.h"

node_t *new_node(int size, void *ptr)
{
    node_t *node = ptr;

    node->memory = ptr + calcul_alignment(sizeof(node_t));
    node->size = calcul_alignment(size);
    node->free = false;
    node->next = NULL;
    return (node);
}

void *new_alloc(node_t **head, size_t size)
{
    node_t *tmp = *head;
    void *ptr = NULL;

    if (!(*head)) {
        ptr = sbrk(0);
        if (check_memory_space(size + sizeof(node_t), 0)) {
            return (NULL);
        }
        *head = new_node(size, ptr);
        get_node(*head, 1);
        return ((*head)->memory);
    }
    for (; tmp->next; tmp = tmp->next);
    if (check_memory_space(size + sizeof(node_t),
    (size_t)sbrk(0) - (size_t)(tmp->memory + tmp->size))) {
        return (NULL);
    }
    tmp->next = new_node(size, tmp->memory + tmp->size);
    get_node(*head, 1);
    return (tmp->next->memory);
}

int check_free(node_t **head, size_t size)
{
    node_t *tmp = *head;

    for (; tmp; tmp = tmp->next) {
        if (tmp->free == true && tmp->size >= size) {
            return (0);
        }
    }
    return (1);
}

void *use_free_memory(node_t **head, size_t size)
{
    node_t *tmp = *head;

    for (; tmp; tmp = tmp->next) {
        if (tmp->free == true && tmp->size >= size) {
            tmp->free = false;
            get_node(*head, 1);
            return (tmp->memory);
        }
    }
    return (NULL);
}

void *malloc(size_t size)
{
    node_t *node = get_node(NULL, 0);

    if (check_pagination() || size <= 0) {
        return (NULL);
    }
    if (!check_free(&node, size)) {
        return (use_free_memory(&node, size));
    }
    return (new_alloc(&node, size));
}