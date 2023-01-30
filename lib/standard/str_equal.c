/*
** EPITECH PROJECT, 2022
** BSQ
** File description:
** str_equal
*/

#include "../../include/pui.h"

bool str_equal(char *str, char *other)
{
    int a = 0, len = str_len(str) + 1;

    while (a < len) {
        if (str[a] != other[a])
            return (false);
        a++;
    }
    return (true);
}
