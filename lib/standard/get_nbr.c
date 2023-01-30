/*
** EPITECH PROJECT, 2022
** BSQ
** File description:
** get_nbr
*/

#include "../../include/pui.h"

bool check_dot(char *src)
{
    int a = 0, count = 0;

    if (!src)
        return (ERROR);
    while (src[a] != '\0') {
        if (src[a] == '.')
            count++;
        if (count > 1 || !is_number(src[a]) && src[a] != '.')
            return (false);
        a++;
    }
    return (true);
}

double get_float(int a, char *src, int num)
{
    double dec = (double)num;
    long long mult = 10;

    while (src[a]) {
        dec += (double)(src[a] - 48) / (double)mult;
        mult *= 10;
        a++;
    }
    return (dec);
}

double get_nbr(char *src)
{
    char *test = !src ? NULL : str_dup(src);
    double num = 0;
    int a = 0;

    if (!test)
        return (ERROR);
    while (test[a]) {
        if (is_number(test[a]))
            num *= 10, num += test[a] - '0';
        if (!is_number(test[a]))
            return (ERROR);
        a++;
    }
    free(test);
    return (num);
}
