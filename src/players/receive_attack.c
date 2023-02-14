/*
** EPITECH PROJECT, 2023
** navy_good
** File description:
** attacks
*/

#include "navy.h"

bool has_hit(char index)
{
    if (index != '.' && index != 'o' && index != 'x')
        return (true);
    return (false);
}

void attack_feedback(map_t *player_map, int enemy_pid)
{
    char index = player_map->board_lines[nbs[1]][nbs[0]];

    if (has_hit(index)) {
        player_map->board_lines[nbs[1]][nbs[0]] = 'x';
        put_char(nbs[0] + 65), put_nbr(nbs[1] + 1), put_string(HIT_MSG);
        player_map->ships--;
        usleep(1000);
        kill((pid_t)enemy_pid, SIGUSR1);
    } else {
        if (index != 'x')
            player_map->board_lines[nbs[1]][nbs[0]] = 'o';
        put_char(nbs[0] + 65), put_nbr(nbs[1] + 1), put_string(MISS_MSG);
        usleep(1000);
        kill((pid_t)enemy_pid, SIGUSR2);
    }
    nbs[2] = 0;
}

void get_coords(int signal)
{
    (void) signal;
    nbs[0]++;
}

void end_coord_transmission(int signal)
{
    (void) signal;
    nbs[0] *= 10;
    nbs[2]++;
}

// * use nbs[0] to get both coordinates of where it hits.
// * Then, the modulo is put onto nbs[1] for further use,
// * to print in map, etc.
void receive_attack(map_t *player_map, int enemy_pid, int *turn)
{
    put_string(WAIT);
    nbs[0] = 0, nbs[1] = 0, nbs[2] = 0;
    while (nbs[2] < 2) {
        signal(SIGUSR1, get_coords);
        signal(SIGUSR2, end_coord_transmission);
    }
    nbs[0] /= 10, nbs[1] = nbs[0] % 10, nbs[0] /= 10;
    nbs[0]--, nbs[1]--;
    attack_feedback(player_map, enemy_pid);
    nbs[3]++;
    (*turn) = me;
}
