/*
** EPITECH PROJECT, 2021
** B-PSU-400-PAR-4-1-malloc-nicolas.allain
** File description:
** malloc
*/

#ifndef MALLOC_H_
#define MALLOC_H_

#include <unistd.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef struct node_s
{
    void *memory;
    size_t size;
    bool free;
    struct node_s *next;
} node_t;

int calcul_alignment(int x);
int check_pagination(void);
int check_memory_space(size_t size, size_t offset);
node_t *get_node(node_t *head, int x);

#endif /* !MALLOC_H_ */
