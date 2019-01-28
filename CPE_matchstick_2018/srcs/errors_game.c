/*
** EPITECH PROJECT, 2019
** errors_game.c
** File description:
** errors_game.c
*/

#include "matchstick.h"

void error_player_turn(map_t *map)
{
    if (map->color == 1)
        my_putstr("\033[35m");
    my_putstr("You lost, too bad...\n");
    if (map->color == 1)
        my_putstr("\033[00m");
    map->status = 2;
}

void error_scan_line(map_t *map)
{
    if (map->color == 1)
        my_putstr("\033[32m");
    my_putstr("Error: invalid output (positive number expected)\n");
}

void error_scan_matches(map_t *map)
{
    if (map->color == 1)
        my_putstr("\033[32m");
    my_putstr("Error: invalid output (positive number expected)\n");
}

void error_num_line(map_t *map, int *lines, int *matches)
{
    error_scan_matches(map);
    scan_lines(map, lines);
    scan_matches(map, matches, lines);
}

int lines_error(int lines, map_t *map)
{
    if (lines < 0) {
        if (map->color == 1)
            my_putstr("\033[32m");
        my_putstr("Error: Invalid output (positive number expected)\n");
        return (1);
    } else if (lines == 0 || lines > map->lines) {
        if (map->color == 1)
            my_putstr("\033[32m");
        my_putstr("Error: this line is out of range\n");
        return (1);
    }
    return (2);
}
