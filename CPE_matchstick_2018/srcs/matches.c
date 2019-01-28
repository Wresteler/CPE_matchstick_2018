/*
** EPITECH PROJECT, 2019
** matches.c
** File description:
** matches.c
*/

#include "matchstick.h"

void rm_matches(map_t *map, int line, int matches, char turn)
{
    int max = map->max_sticks;
    int removed = matches;
    char *str = NULL;

    for (; max >= 0 && matches; max--) {
        str = &map->map[line -1][max];
        if (*str == '|' && matches--)
            *str = 0;
    }
    if (turn == 'p') {
        if (map->color == 1)
            my_putstr("\033[35m");
        my_putstr("Player");
    } else if (turn == 'a') {
        if (map->color == 1)
            my_putstr("\033[35m");
        my_putstr("AI");
    }
    disp_rm(map, removed, line);
}

void disp_rm(map_t *map, int removed, int line)
{
    if (map->color == 1)
        my_putstr("\033[32m");
    my_putstr(" removed ");
    my_put_nbr(removed);
    my_putstr(" match(es) from line ");
    my_put_nbr(line);
    my_putchar('\n');
}

int available_matches(map_t *map, int line)
{
    int matches = 0;

    for (int i = 0; i < map->max_sticks; i++)
        if (map->map[line][i] == '|')
            matches += 1;
    return (matches);
}

int check_sticks(map_t *map, int i)
{
    for (int j = 0; j < map->max_sticks; j++)
        if (map->map[i][j] == '|')
            return (2);
    return (1);
}
