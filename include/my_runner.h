/*
** EPITECH PROJECT, 2018
** My_runner
** File description:
** My_runner.c
*/

#ifndef MY_RUNNER_H
#define MY_RUNNER_H

//#define null_4i {0, 0, 0, 0}
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define WIN 1
#define LOST 0
#define GAME 2
#define END_SCREEN 3

typedef enum type_e {
    Player = 0,
    Layer,
    Enemy
} type_t;

typedef struct game_object_t {
    type_t obj_type;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfIntRect rect;
    float speed;
} game_object;

void init_game(sfClock **clock, sfRenderWindow **window, sfVector2i wndw_size, game_object ***objects, sfFont **font, sfText **text, sfMusic **music);
void destroy_object(game_object **obj, int nb_obs);
game_object *create_object(char const *pts, sfVector2f scale, sfVector2f position);
void init_window(sfRenderWindow **window, char const *title, int width, int height);
void parallax_setup(game_object **objects);
int character_setup(game_object **objects, sfVector2f *obscl_pos, int nb_obs);
void game_loop(sfVector2i wndw_size, game_object **objects, int nb_obs);
void move_parallax(game_object **bckgrnd);
void init_rect(sfIntRect *rect);
void manage_clock(sfClock *clock, int *rect_left, game_object *animated, int *i);
int move_rect(int rect_left);
void player_jump(sfSprite *sprite, sfVector2f pos_player);
void *read_map(char *fp, char *map[2]);
int check_map(char *map[2]);
sfVector2f *get_obs_pos(char *map[2], int length, int nb_obs);
int my_strlen(char *str);
sfVector2f *obscl_appr(char *fp, int *nb_obs);
int collision(sfVector2f obscl_pos, sfVector2f pos_player, int size_obscl, int size_player);
void move_obstacles(game_object *obstacle);
void end_screen(sfRenderWindow *window, int choice);
void create_string(sfFont **font, sfText **text);
char *int_to_str(int nbr);

//my_runner.c
void display_background(sfRenderWindow *window, game_object **objects, int nb_obs, int choice);
void parallax_setup(game_object **objects);
int character_setup(game_object **objects, sfVector2f *obscl_pos, int nb_obs);
void game_loop(sfVector2i wndw_size, game_object **objects, int nb_obs);
void setup(sfVector2f *obscl_pos, int nb_obs);

#endif
