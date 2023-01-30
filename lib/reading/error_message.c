/*
** EPITECH PROJECT, 2023
** antman
** File description:
** error_message
*/

#include "../../include/files.h"

int error_message(void)
{
    write(2, "File is invalid.\n", 17);
    return (84);
}
