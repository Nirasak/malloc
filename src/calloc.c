/*
** EPITECH PROJECT, 2021
** B-PSU-400-PAR-4-1-malloc-nicolas.allain
** File description:
** calloc
*/

#include "my_malloc.h"

void *calloc(size_t nmemb, size_t size)
{
    void *ptr = NULL;

    if (nmemb == 0) {
        ptr = malloc(size);
    } else {
        ptr = malloc(nmemb * size);
    }
    return (memset(ptr, 0, nmemb * size));
}