/*
** EPITECH PROJECT, 2023
** epitech
** File description:
** char-checkers
*/

#include "../../include/pui.h"

bool is_number(char a)
{
    if (a < '0' || a > '9')
        return (false);
    return (true);
}
