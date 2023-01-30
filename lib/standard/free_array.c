/*
** EPITECH PROJECT, 2023
** antman
** File description:
** free_array
*/

#include "../../include/pui.h"
#include "../../include/navy.h"

void free_array(sizes_t **array)
{
    int a = 0;

    while (array[a]) {
        free(array[a]);
        a++;
    }
    free(array);
}

void free_chararray(char **array)
{
    int a = 0;

    while (array[a]) {
        free(array[a]);
        a++;
    }
    free(array);
}
