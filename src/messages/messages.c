/*
** EPITECH PROJECT, 2023
** navy
** File description:
** messages
*/

#include "navy.h"

int help_message(void)
{
    put_string("USAGE\n\t./navy [first_player_pid] navy_positions\nDESCRIPT");
    put_string("ION\n\tfirst_player_pid: only for the 2nd player.");
    put_string(" pid of the first player.\n\tnavy_positions: file repres");
    put_string("enting the positions of the ships.\n");

    return (SUCCESS);
}

int error_help_message(void)
{
    write(2, "Please run with -h for usage information.\n", 42);
    return (FAILURE);
}
