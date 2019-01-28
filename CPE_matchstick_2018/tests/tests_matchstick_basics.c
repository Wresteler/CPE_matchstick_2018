/*
** EPITECH PROJECT, 2019
** tests_matchstick_basics.c
** File description:
** test_matchstick_basics.c
*/

#include "matchstick.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

static void redirect_stdall(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(matchstick, wrong_argument, .init = redirect_stdall)
{
    int result = 0;
    char *av[] = { "./matchstick" };
    char **env = env;

    result = chelou(1, av, env);
    cr_assert_eq(result, 84);
}

Test(matchstick, help_usage, .init = redirect_stdall)
{
    int result = 0;
    char *av[] = { "./matchstick", "-h" };
    char **env = env;

    result = chelou(2, av, env);
    cr_assert_eq(result, 0);
}
