/*
** EPITECH PROJECT, 2019
** basics.c
** File description:
** basics.c
*/

#include "matchstick.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(const char *str)
{
    for (int i = 0; str[i]; i++)
        my_putchar(str[i]);
}

int my_getnbr(char *str)
{
    int val = 0;

    if (str == NULL)
        return (0);
    for (int i = 0; str[i]; i++) {
        for (; str[i] && (str[i] == ' ' || str[i] == '\t'); i++);
        if (str[i] >= '0' && str[i] <= '9') {
            val *= 10;
            val += str[i] - '0';
        } else if (!(str[i] >= '0' && str[i] <= '9') && val != 0)
            return (val);
    }
    return (val);
}

char *my_itoa(unsigned int size)
{
    char *ptr;
    unsigned int i = 0;

    if (!size)
        return (NULL);
    ptr = malloc(sizeof(char) * (size + 1));
    if (ptr == NULL)
        return (NULL);
    while (i < size + 1)
        *(ptr + i++) = 0;

    return (ptr);
}

int my_str_isnum(char *str)
{
    if (str == NULL)
        return (2);
    for (int i = 0; str[i]; i++) {
        for (; str[i] && (str[i] == ' ' || str[i] == '\t'); i++);
        if (str[i] < '0' || str[i] > '9')
            return (1);
    }
    return (0);
}
