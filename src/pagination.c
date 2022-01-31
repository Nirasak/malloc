/*
** EPITECH PROJECT, 2021
** B-PSU-400-PAR-4-1-malloc-nicolas.allain
** File description:
** pagination
*/

#include "my_malloc.h"
#include "unistd.h"

int my_pagesize(int x, int ps)
{
    static int pagesize = 0;

    if (x == 1) {
        pagesize = ps;
    }
    return (pagesize);
}

int calcul_alignment(int x)
{
    return ((x + (15)) & ~(15));
}

int check_memory_space(size_t size, size_t offset)
{
    size_t to_alloc = 0;

    if (size <= offset) {
        return (0);
    }
    to_alloc = calcul_alignment(size) - offset;
    to_alloc /= my_pagesize(0, 0);
    to_alloc *= my_pagesize(0, 0);
    to_alloc += my_pagesize(0, 0);
    if (sbrk(to_alloc) == (void *)-1) {
        return (1);
    }
    return (0);
}

int check_pagination(void)
{
    int pagesize = my_pagesize(0, 0);
    int size = getpagesize();

    if (pagesize == 0 && size != 0 && size % 2 == 0) {
        my_pagesize(1, size * 2);
        return (0);
    } else if (pagesize == 0) {
        return (1);
    }
    return (0);
}