/*
** EPITECH PROJECT, 2023
** navy
** File description:
** map_display
*/

#include "navy.h"

void put_line(char *line)
{
    for (int a = 0; a < 8; a++)
        put_char(line[a]), put_char(' ');
    put_char('\n');
}

void player_map_display(char **player_map)
{
    put_char('\n');
    put_string("my positions:\n");
    put_string(" |A B C D E F G H\n");
    put_string("-+---------------\n");
    put_string("1|"), put_line(player_map[0]);
    put_string("2|"), put_line(player_map[1]);
    put_string("3|"), put_line(player_map[2]);
    put_string("4|"), put_line(player_map[3]);
    put_string("5|"), put_line(player_map[4]);
    put_string("6|"), put_line(player_map[5]);
    put_string("7|"), put_line(player_map[6]);
    put_string("8|"), put_line(player_map[7]);
}

void enemy_map_display(char **enemy_map)
{
    put_string("\nenemy's positions:\n");
    put_string(" |A B C D E F G H\n");
    put_string("-+---------------\n");
    put_string("1|"), put_line(enemy_map[0]);
    put_string("2|"), put_line(enemy_map[1]);
    put_string("3|"), put_line(enemy_map[2]);
    put_string("4|"), put_line(enemy_map[3]);
    put_string("5|"), put_line(enemy_map[4]);
    put_string("6|"), put_line(enemy_map[5]);
    put_string("7|"), put_line(enemy_map[6]);
    put_string("8|"), put_line(enemy_map[7]);
}
