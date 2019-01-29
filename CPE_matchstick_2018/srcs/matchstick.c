/*
** EPITECH PROJECT, 2019
** matchstick.c
** File description:
** matchstick.c
*/

#include "matchstick.h"

int match_it(map_t *map)
{
    int status = 0;

    display_map(map);
    player_turn(map);
    status = map->status;
    destroy_all(map);
    return (status);
}

int matchstick(int ac, char **av)
{
    map_t *map = NULL;
    int i = 0;
    int lines = 0;
    int matches = 0;

    if (color(ac, av) == 1)
        i = 1;
    lines = my_getnbr(av[1 + i]);
    matches = my_getnbr(av[2 + i]);
    if (lines <= 0 || matches <= 0)
        return (84);
    map = init_map(lines, matches);
    if (color(ac, av) == 1)
        map->color = 1;
    if (map == NULL)
        return (84);
    return (match_it(map));
}

int check_params(char **av)
{
    int size = my_getnbr(av[1]);
    int limit = my_getnbr(av[2]);

    if (size <= 1 || size >= 100)
        return (84);
    if (limit < 1)
        return (1);
    return (0);
}
