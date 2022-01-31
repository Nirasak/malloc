/*
** EPITECH PROJECT, 2021
** B-PSU-400-PAR-4-1-malloc-nicolas.allain
** File description:
** realloc_array
*/

#include "my_malloc.h"

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    void *new_ptr = NULL;

    if (nmemb == 0) {
        new_ptr = realloc(ptr, size);
    } else {
        new_ptr = realloc(ptr, nmemb * size);
    }
    return (new_ptr);
}