/*
** EPITECH PROJECT, 2023
** antman
** File description:
** files
*/

#ifndef FILES_H_
    #define FILES_H_

    #include <sys/stat.h>
    #include <fcntl.h>
    #include "./pui.h"

    char *get_file(char *file);
    int error_message(void);
#endif
