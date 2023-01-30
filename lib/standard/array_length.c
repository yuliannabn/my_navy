/*
** EPITECH PROJECT, 2023
** navy
** File description:
** array_length
*/

int arr_len(char **array)
{
    int a = 0;
    while (array[a])
        a++;
    return (a);
}
