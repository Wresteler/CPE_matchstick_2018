/*
** EPITECH PROJECT, 2019
** utils.c
** File description:
** utils.c
*/

#include "matchstick.h"

int my_strlen(char *str)
{
    int i = 0;

    for (; str[i]; i++);
    return (i);
}

void my_put_nbr(int nb)
{
    int a;
    int b;

    if (nb < 0) {
        my_putchar('-');
        my_put_nbr(-nb);
    }
    else {
        b = nb % 10;
        a = nb / 10;
        if (a != 0)
            my_put_nbr(a);
        my_putchar(b + 48);
    }
}
