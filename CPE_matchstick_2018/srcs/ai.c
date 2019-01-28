/*
** EPITECH PROJECT, 2019
** ai.c
** File description:
** ai.c
*/

#include "matchstick.h"

void ai_turn(map_t *map)
{
    int sticks = 0;
    int line = ai_turn_random(map, NULL, 0);
    char turn = 'a';

    ai_turn_it(map);
    sticks = ai_turn_random(map, &line, 1);
    while (sticks > map->max_matches)
        sticks = ai_turn_random(map, &line, 1);
    rm_matches(map, line, sticks, turn);
    display_map(map);
    if (empty_map(map) == 1) {
        if (map->color == 1)
            my_putstr("\033[35m");
        my_putstr("I lost... snif... but I'll get you next time!!\n");
        if (map->color == 1)
            my_putstr("\033[00m");
        map->status = 1;
        return;
    }
    player_turn(map);
}

void ai_turn_it(map_t *map)
{
    if (map->color == 1)
        my_putstr("\033[32m");
    my_putstr("\nAI's turn...\n");
}

int ai_turn_random(map_t *map, int *line, int i)
{
    int max = map->lines;
    int min = 1;
    int j = 0;
    int new = 0;

    srand(time(NULL));
    if (i == 0) {
        j = (rand() % (max - min)) + min;
        if (j <= 0 || j > max)
            return (ai_turn_random(map, NULL, 0));
        return (j);
    }
    new = available_matches(map, *line - 1);
    if (new > 0)
        return (((new == min) ? 1 : (rand() % (new -min)) + min));
    else {
        *line = ((*line + 1 > map->lines) ? 1 : *line + 1);
        return (ai_turn_random(map, line, 1));
    }
}
