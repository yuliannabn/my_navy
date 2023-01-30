/*
** EPITECH PROJECT, 2022
** CPool_07
** File description:
** my_strcat
*/

#include "../../include/pui.h"

char *str_cat(char *dest, char const *src)
{
    int a = 0;
    int dest_len = str_len(dest);
    char *_dest = malloc(8 * (dest_len + str_len(src)) + 1);

    for (int b = 0; dest[b] != '\0'; b++)
        _dest[b] = dest[b];
    for (; src[a] != '\0'; a++)
        _dest[dest_len + a] = src[a];
    _dest[dest_len + a] = '\0';
    return (_dest);
}
