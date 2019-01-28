/*
** EPITECH PROJECT, 2019
** launch.c
** File description:
** launch.c
*/

#include "matchstick.h"

int launch(int ac, char **av, char **env)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        display_help();
        return (0);
    } else if (env_err(env) == 1)
        return (84);
    else if (color(ac, av) == 1)
        return (matchstick(ac, av));
    else if (errors(ac, av) == 1)
        return (84);
    else
        return (matchstick(ac, av));
}
