/*
** EPITECH PROJECT, 2019
** My_runner
** File description:
** End game related functions
*/

#include "my_runner.h"

void end_screen(sfRenderWindow *window, int choice)
{
    game_object *end_screen;

    if (choice == WIN) {
        end_screen = create_object("res/win.png", (sfVector2f){1, 1}, (sfVector2f){0, 0});
    }
    if (choice == LOST) {
        end_screen = create_object("res/lost.png", (sfVector2f){1, 1}, (sfVector2f){0, 0});
    }
    sfRenderWindow_drawSprite(window, end_screen->sprite, NULL);
}
