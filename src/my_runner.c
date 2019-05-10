/*
** EPITECH PROJECT, 2018
** My_runner
** File description:
** My_runner principal file
*/

#include "my_runner.h"

void display_background(sfRenderWindow *window, game_object **objects, int nb_obs, int choice)
{
    if (choice == 0) {
        sfRenderWindow_drawSprite(window, objects[5]->sprite, NULL);
        sfRenderWindow_drawSprite(window, objects[3]->sprite, NULL);
        sfRenderWindow_drawSprite(window, objects[8]->sprite, NULL);
        sfRenderWindow_drawSprite(window, objects[2]->sprite, NULL);
        sfRenderWindow_drawSprite(window, objects[7]->sprite, NULL);
        sfRenderWindow_drawSprite(window, objects[1]->sprite, NULL);
        sfRenderWindow_drawSprite(window, objects[6]->sprite, NULL);
    }
    if (choice == 1) {
        sfRenderWindow_drawSprite(window, objects[4]->sprite, NULL);
        for (int i = 1; i != nb_obs; i++) {
            sfRenderWindow_drawSprite(window, objects[i + 8]->sprite, NULL);
        }
        sfRenderWindow_drawSprite(window, objects[0]->sprite, NULL);
    }
}

void parallax_setup(game_object **objects)
{
    objects[0] = create_object("res/fore.png", (sfVector2f){1, 1}, (sfVector2f){0, 0});
    objects[1] = create_object("res/foreground.png", (sfVector2f){2.75, 1}, (sfVector2f){0, 770});
    objects[2] = create_object("res/midgrnd.png", (sfVector2f){1, 1}, (sfVector2f){0, 300});
    objects[3] = create_object("res/midgrnd2.png", (sfVector2f){1, 1}, (sfVector2f){0, 250});
    objects[5] = create_object("res/backgrnd.png", (sfVector2f){4, 1}, (sfVector2f){0, 0});
    objects[6] = create_object("res/foreground.png", (sfVector2f){2.75, 1}, (sfVector2f){1920, 770});
    objects[7] = create_object("res/midgrnd.png", (sfVector2f){1, 1}, (sfVector2f){1920, 300});
    objects[8] = create_object("res/midgrnd2.png", (sfVector2f){1, 1}, (sfVector2f){1920, 250});
}

int character_setup(game_object **objects, sfVector2f *obscl_pos, int nb_obs)
{
    objects[4] = create_object("res/character.png", (sfVector2f){1.5, 1.5}, (sfVector2f){250, 780});
    for (int i = 0; i != nb_obs; i++) {
        objects[i + 8] = create_object("res/enn.png", (sfVector2f){1.5, 1.5}, obscl_pos[i]);
    }
    return (nb_obs);
}

void game_loop(sfVector2i wndw_size, game_object **objects, int nb_obs)
{
    sfRenderWindow *window;
    sfMusic *music = sfMusic_createFromFile("res/music.ogg");
    sfEvent event;
    sfClock *clock = sfClock_create();
    int choice = GAME;
    int end_status;
    sfVector2f pos;
    int score = 0;
    sfFont *font;
    sfText *text;

    init_game(&clock, &window, wndw_size, &objects, &font, &text, &music);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        sfRenderWindow_clear(window, sfBlack);
        if (choice == GAME) {
            display_background(window, objects, 0, 0);
            move_parallax(objects);
            player_jump(objects[4]->sprite, sfSprite_getPosition(objects[4]->sprite));
            manage_clock(clock, &objects[4]->rect.left, objects[4], &score);
            for (int i = 1; i != nb_obs; i++)
                move_obstacles(objects[i + 8]);
            for (int i = 1; i != nb_obs; i++) {
                pos = sfSprite_getPosition(objects[i + 8]->sprite);
                choice = collision(pos, sfSprite_getPosition(objects[4]->sprite), 60, 60);
                end_status = LOST;
                if (choice == END_SCREEN)
                    break;
            }
            if (pos.x <= -100) {
                choice = END_SCREEN;
                end_status = WIN;
            }
            sfText_setString(text, int_to_str(score));
            sfRenderWindow_drawSprite(window, text, NULL);
            display_background(window, objects, nb_obs, 1);
        }
        if (choice == END_SCREEN)
            end_screen(window, end_status);
        sfRenderWindow_display(window);
    }
    sfMusic_destroy(music);
    destroy_object(objects, nb_obs);
    sfRenderWindow_destroy(window);
}

void setup(sfVector2f *obscl_pos, int nb_obs)
{
    game_object *objects[nb_obs + 8];

    character_setup(&objects, obscl_pos, nb_obs);
    parallax_setup(objects);
    objects[4]->rect.left = 0;
    game_loop((sfVector2i){1920, 1080}, objects, nb_obs);
}
