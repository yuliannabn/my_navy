/*
** EPITECH PROJECT, 2023
** navy
** File description:
** main
*/

#include "navy.h"

int main(int argc, char **arg)
{
    int nbr = 0;

    if (argc == 2) {
        if (str_equal(arg[1], "-h"))
            return (help_message());
        if ((open(arg[1], O_RDONLY)) > ERROR)
            return (navygame(arg[1], me, 0));
    } if (argc == 3) {
        nbr = get_nbr(arg[1]);
        if ((open(arg[2], O_RDONLY)) > ERROR && nbr > ERROR)
            return (navygame(arg[2], you, nbr));
    }
    return (error_help_message());
}
