/*
** EPITECH PROJECT, 2019
** matchstick.h
** File description:
** matchstick.h
*/

#ifndef MATCHSTICK_H_
#define MATCHSTICK_H_

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

#ifndef READ_SIZE
#define READ_SIZE 1

typedef struct s_map {
    char **map;
    int lines;
    int max_matches;
    int max_sticks;
    int status;
    int exit;
    int color;
} map_t;

int launch(int, char **, char **);

void my_putchar(char);
void my_putstr(const char *);
int my_getnbr(char *);
int my_str_isnum(char *);
char *my_itoa(unsigned int);

int my_strlen(char *);
void my_put_nbr(int);

char *my_realloc(char *);
char *get_next_line(int);

void display_help(void);

int errors(int, char **);
int color(int, char **);
int matches_error(int, int, map_t *);
int matches_error2(int, int, map_t *);
int env_err(char **);

void error_player_turn(map_t *);
void error_scan_line(map_t *);
void error_scan_matches(map_t *);
void error_num_line(map_t *, int *, int *);
int lines_error(int, map_t *);

int check_params(char **);
int matchstick(int, char **);
int match_it(map_t *);

void destroy_all(map_t *);

char **create_map(int, int);
map_t *init_map(int, int);
void display_map(map_t *);
void display_charac(int, int, map_t *);
int empty_map(map_t *);

void player_turn(map_t *);
void scan_lines(map_t *, int *);
void scan_matches(map_t *, int *, int *);
void disp_matches(map_t *);
void my_exit(map_t *);

void rm_matches(map_t *, int, int, char);
void disp_rm(map_t *, int, int);
int available_matches(map_t *, int);
int check_sticks(map_t *, int);

void ai_turn(map_t *);
void ai_turn_it(map_t *);
int ai_turn_random(map_t *, int *, int);

#endif
#endif
