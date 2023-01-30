/*
** EPITECH PROJECT, 2023
** antman
** File description:
** file_insides
*/

#include "../../include/files.h"

char *get_file(char *file)
{
    int fd = open(file, O_RDONLY);
    char info[1025 + 1], *end = "";
    int len = 0, ret = 0;

    while ((len = read(fd, info, 1025)) > 0) {
        info[len] = '\0';
        end = str_cat(end, info);
    }
    if ((ret = close(fd)) > ERROR)
        return (end);
    return (NULL);
}
