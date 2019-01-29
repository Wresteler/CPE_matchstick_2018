/*
** EPITECH PROJECT, 2019
** map.c
** File description:
** map.c
*/

#include "matchstick.h"

map_t *init_map(int lines, int matches)
{
    map_t *map = malloc(sizeof(map_t));

    if (map == NULL)
        return (NULL);
    map->color = 0;
    map->max_sticks = 1 + (lines - 1) * 2;
    map->map = create_map(lines, map->max_sticks);
    if (map->map == NULL) {
        free(map);
        return (NULL);
    }
    map->lines = lines;
    map->max_matches = matches;
    map->status = 0;
    return (map);
}

char **create_map(int lines, int max_sticks)
{
    int sticks = 0;
    int flag = 0;
    char **s_map = malloc(sizeof(*s_map) * (lines + 1));

    if (s_map == NULL)
        return (NULL);
    for (int i = 0; i < lines; i++) {
        s_map[i] = my_itoa(max_sticks);
        if (s_map[i] == NULL)
            return (NULL);
        sticks = (1 + i * 2);
        flag = ((max_sticks - sticks) / 2);
        while (sticks--)
            s_map[i][flag++] = '|';
    }
    s_map[lines] = NULL;
    return (s_map);
}

void display_map(map_t *map)
{
    for (int i = 0; i <map->lines + 2; i++) {
        for (int j = 0; j < map->max_sticks + 2; j++)
            display_charac(i, j, map);
        my_putchar('\n');
    }
}

void display_charac(int i, int j, map_t *map)
{
    char display = '*';

    if (!(!j || j == map->max_sticks + 1 || !i || i == map->lines + 1))
        display = (map->map[i - 1][j - 1] ? map->map[i - 1][j - 1] : ' ');
    if (display == '*' && map->color == 1)
        my_putstr("\033[01m\033[31m");
    if (display == '|' && map->color == 1)
        my_putstr("\033[1;36m");
    my_putchar(display);
}

int empty_map(map_t *map)
{
    for (int i = 1; i < map->lines; i++)
        if (check_sticks(map, i) == 2)
            return (2);
    return (1);
}
