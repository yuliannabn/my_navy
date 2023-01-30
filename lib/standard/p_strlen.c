/*
** EPITECH PROJECT, 2023
** pui_print
** File description:
** get string length
*/
#include <stdio.h>

int str_len(char *string)
{
    int a = 0;

    while (string[a])
        a++;
    return (a);
}
