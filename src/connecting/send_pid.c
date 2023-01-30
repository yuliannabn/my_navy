/*
** EPITECH PROJECT, 2023
** navy_good
** File description:
** connect_pid
*/

#include "navy.h"

void send_number(pid_t receiver, int times)
{
    while (times >= 0) {
        usleep(1000);
        kill(receiver, SIGUSR1);
        times--;
    }
}

void pid_received(int signal)
{
    (void)signal;
    nbs[1] = -1;
}

void validate_pid(int check)
{
    if (check > 1) {
        nbs[1] = -2;
        write(2, "The pid is incorrect.\n", 22);
    } else
        put_string("successfully connected\n");
}

void send_pid(pid_t receiver, pid_t sender)
{
    char *pid_str = str_num(sender);
    int a = 0, check = 0;

    while (pid_str[a]) {
        send_number(receiver, (pid_str[a] - 48));
        usleep(1000);
        kill(receiver, SIGUSR2);
        usleep(1000);
        a++;
    }
    usleep(1000);
    kill(receiver, SIGUSR2);
    while (check < 2 && nbs[1] > -1) {
        signal(SIGUSR2, pid_received);
        check++;
        usleep(10000);
    }
    validate_pid(check);
}
