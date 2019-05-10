/*
** EPITECH PROJECT, 2018
** My_runnre
** File description:
** My_runner's bootstrap
*/

#include "my_runner.h"

void init_window(sfRenderWindow **window, char const *title, int width, int height)
{
    sfVideoMode mode = {width, height, 32};

    *window = sfRenderWindow_create(mode, title, sfClose, NULL);
}

void init_rect(sfIntRect *rect)
{
    rect->top = 0;
    rect->left = 0;
    rect->width = 60;
    rect->height = 85;
}

game_object *create_object(char const *pts, sfVector2f scale, sfVector2f position)
{
    game_object *object = malloc(sizeof(game_object));

    object->texture = sfTexture_createFromFile(pts, NULL);
    if (object->texture == NULL)
        return (NULL);
    object->sprite = sfSprite_create();
    if (object->sprite == NULL)
        return (NULL);
    sfSprite_setScale(object->sprite, scale);
    sfSprite_setPosition(object->sprite, position);
    sfSprite_setTexture(object->sprite, object->texture, sfTrue);
    return (object);
}

void destroy_object(game_object **obj, int nb_obs)
{
    for (int i = 0; i != nb_obs; i++) {
        sfTexture_destroy(obj[i]->texture);
        sfSprite_destroy(obj[i]->sprite);
    }
}

void manage_clock(sfClock *clock, int *rect_left, game_object *animated, int *i)
{
    sfTime time;

    time = sfClock_getElapsedTime(clock);
    if (sfTime_asSeconds(time) > 0.5) {
        *rect_left = move_rect(*rect_left);
        sfSprite_setTextureRect(animated->sprite, animated->rect);
        *i += 1;
        time = sfClock_restart(clock);
    }
}
