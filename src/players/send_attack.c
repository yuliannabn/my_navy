/*
** EPITECH PROJECT, 2023
** navy_good
** File description:
** attacks
*/

#include "navy.h"

void send_attack(int pid, int pos)
{
    send_number(pid, pos);
    usleep(1000);
    kill(pid, SIGUSR2);
}

void has_worked(int signal)
{
    (void) signal;
    nbs[2] = HAS_HIT;
}

void has_not_worked(int signal)
{
    (void) signal;
    nbs[2] = NO_HIT;
}

bool attack_worked(map_t *enemy_map)
{
    nbs[2] = 0;
    while (nbs[2] == 0) {
        signal(SIGUSR1, has_worked);
        signal(SIGUSR2, has_not_worked);
    }
    if (nbs[2] == HAS_HIT) {
        enemy_map->ships--;
        enemy_map->board_lines[nbs[1]][nbs[0]] = 'x';
        return (true);
    } else if (enemy_map->board_lines[nbs[1]][nbs[0]] != 'x')
        enemy_map->board_lines[nbs[1]][nbs[0]] = 'o';
    return (false);
}

void init_attack(int *turn, int pid, map_t *enemy_map)
{
    bool has_attacked = false;
    char buf[100];

    while (!has_attacked) {
        put_string("\nattack: ");
        if (!attack_is_valid(buf))
            continue;
        send_attack(pid, nbs[0]), send_attack(pid, nbs[1]);
        if (attack_worked(enemy_map))
            put_string(cut_str(buf)), put_string(HIT_MSG);
        else
            put_string(cut_str(buf)), put_string(MISS_MSG);
        break;
    }
    nbs[3]++;
    (*turn) = you;
}
