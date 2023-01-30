/*
** EPITECH PROJECT, 2023
** navy_good
** File description:
** get_pid
*/

#include "navy.h"

void get_pid(int signal)
{
    (void) signal;
    nbs[1] = 0;
    nbs[0] += 1;
}

void end_pid(int signal)
{
    (void) signal;
    nbs[1]++;
    nbs[0] -= nbs[1] < 2 ? 1 : 0;
    nbs[0] *= nbs[1] < 2 ? 10 : 1;
}
