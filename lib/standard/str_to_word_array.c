/*
** EPITECH PROJECT, 2022
** CPool_08
** File description:
** my_str_to_word_array
*/

#include "../../include/pui.h"

char *my_strmalloc(int size)
{
    int i = 0;
    char *str = malloc(sizeof(char) * (size + 1));

    if (str == NULL)
        return (NULL);
    while (i <= size) {
        str[i] = '\0';
        i++;
    }
    return (str);
}

int nb_cages (char *str, char sep)
{
    int num = 1;
    int i = 0;

    for (; str[i] != '\0'; i++)
        if (i > 0 && str[i + 1] && (str[i] == sep) && str[i + 1] != sep)
            num++;
    if (str[0] && str[0] == sep && str[1] && str[1] == sep)
        num -= 1;
    return (num);
}

int main_loop(int num, char **result, char *str, char sep)
{
    int j = 0, z = 0, x = 0, i = 0;

    for (;j < num; x = 0) {
        while (str[x + z] != '\0' && str[x + z] != sep)
            x++;
        if (x == 0 && str[x + z] == sep) {
            z++;
            continue;
        }
        result[j] = my_strmalloc(x + 1);
        if (!result[j])
            return (ERROR);
        for (i = 0; i < x; i++, z++)
            result[j][i] = str[z];
        result[j][i] = '\0';
        z++;
        j++;
    }
    return (j);
}

char **param_str_array(char *str, char sep)
{
    int num = str ? nb_cages(str, sep) : 0, last_index;
    char **result = malloc((num + 1) * sizeof(char *));

    if (!result || !str)
        return (NULL);
    last_index = main_loop(num, result, str, sep);
    if (last_index == ERROR)
        return (NULL);
    result[last_index] = NULL;
    return (result);
}
