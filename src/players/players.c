/*
** EPITECH PROJECT, 2023
** navy_good
** File description:
** players
*/

#include "navy.h"

void check_victory_status(map_t *player_map, map_t *enemy_map)
{
    player_map_display(player_map->board_lines);
    enemy_map_display(enemy_map->board_lines);
    if (player_map->ships > 0) {
        put_string(WIN_MSG);
        player_map->ret = I_WON;
    } else {
        put_string(FAIL_MSG);
        player_map->ret = ENEM_WON;
    }
}

// ! nbs is a global array whose indexes will be:
// * nbs[0] = attack [number] - 49, nbs[1] = attack [letter] - 65
// * nbs[2] = HAS_HIT / NO_HIT, nbs[3] = END_OF_ROUND / START_OF_ROUND
// * will only display map after both players have finished.
// * else, wait and defend, or attack
void attack_and_defend(map_t *player_map, map_t *enemy_map, int *turn)
{
    while (player_map->ships > 0 && enemy_map->ships > 0) {
        if (nbs[3] == END_OF_ROUND) {
            player_map_display(player_map->board_lines);
            enemy_map_display(enemy_map->board_lines);
            nbs[3] = START_OF_ROUND;
        }
        if ((*turn) == me)
            init_attack(turn, enemy_map->PID, enemy_map);
        else
            receive_attack(player_map, enemy_map->PID, turn);
    }
    check_victory_status(player_map, enemy_map);
}

int player1(map_t *player_map, map_t *enemy_map)
{
    int turn = me, ret = 0;

    pid_wait(player_map->PID);
    enemy_map->PID = (pid_t)nbs[0];
    attack_and_defend(player_map, enemy_map, &turn);
    ret = player_map->ret;
    free_map(player_map), free_map(enemy_map);
    return (ret);
}

int player2(map_t *player_map, map_t *enemy_map, int pid)
{
    int turn = you, ret = 0;

    enemy_map->PID = (pid_t)pid;
    put_string("my_pid: "), put_nbr(player_map->PID), put_char('\n');
    send_pid(pid, player_map->PID);
    if (nbs[1] == -2)
        return (FAILURE);
    attack_and_defend(player_map, enemy_map, &turn);
    ret = player_map->ret;
    free_map(player_map), free_map(enemy_map);
    return (ret);
}
