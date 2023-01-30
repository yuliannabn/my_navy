/*
** EPITECH PROJECT, 2023
** navy
** File description:
** init
*/

#include "navy.h"

char **segment_parts(char *lines)
{
    char **new = param_str_array(lines, '\n');
    if (new) {
        free(lines);
        return (new);
    }
    return (NULL);
}

sizes_t **init_sizes(void)
{
    sizes_t **sizes = malloc(sizeof(size_t) * 5);

    sizes[0] = malloc(sizeof(size_t));
    sizes[0]->size = small;
    sizes[0]->on = false;
    sizes[1] = malloc(sizeof(size_t));
    sizes[1]->size = medium;
    sizes[1]->on = false;
    sizes[2] = malloc(sizeof(size_t));
    sizes[2]->size = big;
    sizes[2]->on = false;
    sizes[3] = malloc(sizeof(size_t));
    sizes[3]->size = huge;
    sizes[3]->on = false;
    sizes[4] = NULL;
    return (sizes);
}

map_t *init_map(void)
{
    map_t *map = malloc(sizeof(map_t));
    map->board_lines = malloc(sizeof(char *) * (BOARD_SIZE + 1));
    map->ships = TOTAL_SHIPS;
    map->ret = I_WON;
    map->PID = getpid();
    int a = 0;

    while (a < BOARD_SIZE) {
        map->board_lines[a] = str_dup(board_line);
        a++;
    }
    map->board_lines[a] = NULL;
    return (map);
}

bool navy_initialize(char *file, map_t *player_map)
{
    char **data = segment_parts(get_file(file));

    if (data != NULL)
        if (sizes_valid(data) && positions_valid_fill(data, player_map)) {
            free_chararray(data);
            return (true);
        }
    error_message();
    error_help_message();
    return (false);
}

void free_map(map_t *map)
{
    free_chararray(map->board_lines);
    free(map);
}
