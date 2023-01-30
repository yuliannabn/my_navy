/*
** EPITECH PROJECT, 2023
** pui_print
** File description:
** pui
*/

#ifndef PUI_H_
    #define PUI_H_

    #include <stdio.h>
    #include <unistd.h>
    #include <stdlib.h>

    #define bool int
    #define true 1
    #define false 0

    #define FAILURE 84
    #define ERROR -1
    #define SUCCESS 0

    int str_len(char const *string);
    void put_char(char a);
    void put_nbr(int number);
    int arr_len(char **array);
    char *number_string(int number);
    double get_nbr(char *src);
    double get_float(int a, char *src, int num);
    void put_float(float number, int decimals);
    void put_string(char *string);
    char *str_num(int number);
    char *str_dup(char const *src);
    char *str_cat(char *dest, char const *src);
    char **param_str_array(char *str, char sep);
    bool str_equal(char *str, char *other);
    bool is_number(char a);
#endif
