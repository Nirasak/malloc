/*
** EPITECH PROJECT, 2021
** B-PSU-400-PAR-4-1-malloc-nicolas.allain
** File description:
** get_node
*/

#include "my_malloc.h"

node_t *get_node(node_t *head, int x)
{
    static node_t *node = NULL;

    if (x == 1) {
        node = head;
    }
    return (node);
}