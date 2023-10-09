#include "shell.h"

/**
 * _memset - fills memory with a constant byte
 * @s: the pointer to the memory area
 * @b: the byte to fill *s with
 * @n: the amount of bytes to be filled
 * Return: a pointer to the memory area s
 */
void *_memset(void *s, int b, size_t n)
{
    unsigned char *ptr = s;
    unsigned char value = b;
    size_t i;

    for (i = 0; i < n; i++)
        ptr[i] = value;

    return s;
}

/**
 * ffree - frees a string of strings
 * @pp: string of strings
 */
void ffree(char **pp)
{
    if (!pp)
        return;

    char **tmp = pp;
    while (*pp)
    {
        free(*pp);
        pp++;
    }

    free(tmp);
}

/**
 * _realloc - reallocates a block of memory
 * @ptr: pointer to previous malloc'ated block
 * @old_size: byte size of previous block
 * @new_size: byte size of new block
 *
 * Return: pointer to the reallocated block of memory
 */
void *_realloc(void *ptr, size_t old_size, size_t new_size)
{
    if (!ptr)
        return malloc(new_size);

    if (new_size == 0)
    {
        free(ptr);
        return NULL;
    }

    void *new_ptr = malloc(new_size);
    if (!new_ptr)
        return NULL;

    size_t copy_size = old_size < new_size ? old_size : new_size;
    _memcpy(new_ptr, ptr, copy_size);
    free(ptr);

    return new_ptr;
}
