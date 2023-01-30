/*
** EPITECH PROJECT, 2022
** MyHunter
** File description:
** nbr_string
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int s_count(int number)
{
    int a = 0;

    while (number > 0) {
        number /= 10;
        a++;
    }
    return (a);
}

char *str_num(int number)
{
    char *str = malloc(sizeof(char) * (s_count(number) + 1));
    int a = s_count(number);

    if (number < 10 && number > -1) {
        str[0] = number + 48;
        str[1] = '\0';
    }
    if (number > 9) {
        for (int b = 0; b < a; str[b] = ' ', b++);
        str[a] = '\0';
        a--;
        while (a >= 0) {
            str[a] = (number % 10) + 48;
            number /= 10;
            a--;
        }
    }
    return (str);
}
