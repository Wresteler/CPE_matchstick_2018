/*
** EPITECH PROJECT, 2019
** free.c
** File description:
** free.c
*/

#include "matchstick.h"

void destroy_all(map_t *map)
{
    for (int i = 0; map->map[i] != NULL; i++)
        free(map->map[i]);
    free(map->map);
    free(map);
}
