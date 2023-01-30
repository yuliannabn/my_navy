/*
** EPITECH PROJECT, 2023
** navy_good
** File description:
** val_tools
*/

#include "navy.h"

void pid_wait(int PID)
{
    put_string("my_pid: "), put_nbr(PID);
    put_string("\nwaiting for enemy connection...\n");

    while (nbs[1] < 2) {
        signal(SIGUSR1, get_pid);
        signal(SIGUSR2, end_pid);
    }
    nbs[0] /= 10;
    kill(nbs[0], SIGUSR2);
    put_string("\nenemy connected\n");
}

bool out_of_bounds(int nb)
{
    if (nb > (BOARD_SIZE - 1) || nb < 0)
        return (true);
    return (false);
}

char *cut_str(char *str)
{
    int len = str_len(str) - 1;
    char *new = malloc(sizeof(char) * (len + 1));
    int a = 0;

    while (a < len) {
        new[a] = str[a];
        a++;
    }
    new[a] = '\0';
    return (new);
}

bool attack_is_valid(char *buf)
{
    int len = 0;

    while ((len = read(0, buf, 99)) == 0)
        continue;
    buf[len] = '\0';
    if (buf[len - 1] == '\n')
        nbs[0] = buf[0] - 65, nbs[1] = buf[1] - 49;
    if ((out_of_bounds(nbs[0]) || out_of_bounds(nbs[1])) || len > 3) {
        put_string("wrong position");
        return (false);
    }
    return (true);
}
