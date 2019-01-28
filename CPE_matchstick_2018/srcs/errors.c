/*
** EPITECH PROJECT, 2019
** errors.c
** File description:
** errors.c
*/

#include "matchstick.h"

int errors(int ac, char **av)
{
    if (ac != 3) {
        write(2, "Invalid arguments number.\n", 26);
        write(2, "Usage: ./matchstick [lines] [max_matches]\n", 42);
        return (1);
    } else if (check_params(av) == 84) {
        write(2, "Error: nb of lines must be between 2 and 99!\n", 45);
        return (1);
    } else if (check_params(av) == 1) {
        write(2, "Error: nb of sticks must be a positive number!\n", 47);
        return (1);
    }
    return (2);
}

int color(int ac, char **av)
{
    if (ac == 4 && av[1][0] == '-' && av[1][1] == 'c')
        return (1);
    return (2);
}

int matches_error(int matches, int lines, map_t *map)
{
    if (matches == 0) {
        if (map->color == 1)
            my_putstr("\033[32m");
        my_putstr("Error: you have to remove at least one match\n");
        return (1);
    } else if (matches > map->max_matches) {
        if (map->color == 1)
            my_putstr("\033[32m");
        my_putstr("Error: you cannot remove more than ");
        my_put_nbr(map->max_matches);
        my_putstr(" matches per turn\n");
        return (1);
    } else if ((matches_error2(matches, lines, map)) == 1)
        return (1);
    return (2);
}

int matches_error2(int matches, int lines, map_t *map)
{
    if (matches < 0) {
        if (map->color == 1)
            my_putstr("\033[32m");
        my_putstr("Error: Invalid output (positive number expected)\n");
        return (1);
    } else if (matches > available_matches(map, lines - 1)) {
        if (map->color == 1)
            my_putstr("\033[32m");
        my_putstr("Error: not enougth matches on this line\n");
        return (1);
    }
    return (2);
}

int env_err(char **env)
{
    if (env[0] == NULL) {
        write(2, "Error: NULL environment!\n", 25);
        return (1);
    }
    return (0);
}
