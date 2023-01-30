/*
** EPITECH PROJECT, 2023
** pui_print
** File description:
** display a string
*/

#include "../../include/pui.h"

void put_string(char *string)
{
    write(1, string, str_len(string));
}
