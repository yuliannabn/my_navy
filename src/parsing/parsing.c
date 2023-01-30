/*
** EPITECH PROJECT, 2023
** navy
** File description:
** parsing
*/

#include "navy.h"

int trav_sizes(char *line, sizes_t **sizes)
{
    for (int b = 0; sizes[b]; b++) {
        if (line[0] == sizes[b]->size && !sizes[b]->on) {
            sizes[b]->on = true;
            return (1);
        }
    }
    return (0);
}

bool sizes_valid(char **data)
{
    sizes_t **sizes = init_sizes();
    bool valid = arr_len(data) == all_sizes ? true : false;
    int count = 0;

    if (valid) {
        for (int a = 0; data[a]; a++)
            count += trav_sizes(data[a], sizes);
    }
    free_array(sizes);
    if (count == all_sizes)
        return (true);
    error_message();
    return (false);
}

bool is_valid_pos(char *position)
{
    if ((position[from_hor] - 65) > 7 || (position[from_ver] - 49) > 7
    || (position[to_hor] - 65) > 7 || (position[to_ver] - 49) > 7)
        return (false);
    if ((position[from_hor] - 65) < 0 || (position[from_ver] - 49) < 0
    || (position[to_hor] - 65) < 0 || (position[to_ver] - 49) < 0)
        return (false);
    return (true);
}

void fill_map(char *ship_pos, char **map)
{
    int let1 = ship_pos[from_hor] - 65, n1 = ship_pos[from_ver] - 49;
    int let2 = ship_pos[to_hor] - 65, n2 = ship_pos[to_ver] - 49;
    int times = ship_pos[0] - 48;
    int invh = (let1 - let2) < 0 ? 1 : -1;
    int invv = n1 - n2 < 0 ? 1 : -1;
    int a = 0;

    invh = (let1 == let2) ? 0 : invh, invv = (n1 == n2) ? 0 : invv;
    while (a < times) {
        map[n1][let1] = ship_pos[0];
        let1 += invh;
        n1 += invv;
        a++;
    }
}

bool positions_valid_fill(char **data, map_t *player_map)
{
    int a = 0;

    while (data[a]) {
        if (!is_valid_pos(data[a])) {
            write(2, "The positions are out of range.\n", 32);
            return (false);
        }
        fill_map(data[a], player_map->board_lines);
        a++;
    }
    return (true);
}
