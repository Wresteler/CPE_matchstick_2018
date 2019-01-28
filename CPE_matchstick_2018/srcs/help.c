/*
** EPITECH PROJECT, 2019
** help.c
** File description:
** help.c
*/

#include "matchstick.h"

void display_help(void)
{
    my_putstr("\n Usage:\n\t");
    my_putstr("./matchsitck [lines] [max_matches]\n\n");
    my_putstr(" For a \033[5m\033[33m\033[01mcolored");
    my_putstr("\033[0m\033[01m\033[31m game:\n");
    my_putstr("\t\033[0m./matchstick -c [lines] [max_matches]\n\n");
    my_putstr(" Game:\n\t");
    my_putstr("-h Display help usage\n\t");
    my_putstr("lines and matches must be a positive number\n");
    my_putstr("\t1 < lines < 100\n\n");
}
