/*
** EPITECH PROJECT, 2023
** navy
** File description:
** navy
*/

#include "navy.h"
long int nbs[4];

int navygame(char *file, int mode, int pid)
{
    map_t *player_map = init_map();
    map_t *enemy_map = init_map();
    nbs[0] = 0, nbs[1] = 1, nbs[2] = 0, nbs[3] = 2;

    if (navy_initialize(file, player_map)) {
        if (mode == me)
            return (player1(player_map, enemy_map));
        if (mode == you)
            return (player2(player_map, enemy_map, pid));
    }
    free_chararray(player_map->board_lines);
    free_chararray(enemy_map->board_lines);
    free(player_map), free(enemy_map);
    return (FAILURE);
}
