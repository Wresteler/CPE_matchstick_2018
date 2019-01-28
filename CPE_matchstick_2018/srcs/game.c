/*
** EPITECH PROJECT, 2019
** game.c
** File description:
** game.c
*/

#include "matchstick.h"

void player_turn(map_t *map)
{
    int lines = 0;
    int matches = 0;
    char turn = 'p';

    if (map->color == 1)
        my_putstr("\033[5m\033[32m");
    my_putstr("\nYour turn :\n");
    scan_lines(map, &lines);
    if (map->exit == 1)
        return;
    scan_matches(map, &matches, &lines);
    if (map->exit == 1)
        return;
    rm_matches(map, lines, matches, turn);
    display_map(map);
    if (empty_map(map) == 1) {
        error_player_turn(map);
        return;
    }
    ai_turn(map);
}

void scan_lines(map_t *map, int *lines)
{
    char *line = NULL;

    if (map->color == 1)
        my_putstr("\033[00m\033[1;36m");
    my_putstr("Line: ");
    line = get_next_line(0);
    if (line == NULL) {
        my_exit(map);
        return;
    }
    if (my_str_isnum(line) == 1) {
        error_scan_line(map);
        scan_lines(map, lines);
        return;
    }
    *lines = my_getnbr(line);
    if (map->exit == 1)
        return;
    if (lines_error(*lines, map) == 1)
        scan_lines(map, lines);
}

void scan_matches(map_t *map, int *matches, int *lines)
{
    char *line = NULL;

    disp_matches(map);
    line = get_next_line(0);
    if (line == NULL) {
        my_exit(map);
        return;
    } if (my_str_isnum(line) == 1) {
        error_num_line(map, lines, matches);
        return;
    }
    *matches = my_getnbr(line);
    if (matches_error(*matches, *lines, map) == 1) {
        scan_lines(map, lines);
        if (map->exit == 1)
            return;
        scan_matches(map, matches, lines);
        if (map->exit == 1)
            return;
    }
}

void disp_matches(map_t *map)
{
    if (map->color == 1)
        my_putstr("\033[1;36m");
    my_putstr("Matches: ");
}

void my_exit(map_t *map)
{
    map->exit = 1;
    if (map->color == 1)
        my_putstr("\033[0m");
}
