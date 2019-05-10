/*
** EPITECH PROJECT, 2018
** My_runner
** File description:
** My_runner move functions
*/

#include "my_runner.h"

void move_parallax(game_object **bckgrnd)
{
    sfVector2f position = sfSprite_getPosition(bckgrnd[0]->sprite);
    sfVector2f position2 = sfSprite_getPosition(bckgrnd[2]->sprite);
    sfVector2f position2_bis = sfSprite_getPosition(bckgrnd[7]->sprite);
    sfVector2f position3 = sfSprite_getPosition(bckgrnd[3]->sprite);
    sfVector2f position3_bis = sfSprite_getPosition(bckgrnd[8]->sprite);
    sfVector2f position_bis = sfSprite_getPosition(bckgrnd[1]->sprite);
    sfVector2f position_bis2 = sfSprite_getPosition(bckgrnd[6]->sprite);

    if (position.x <= -1920)
        position.x = 1920;
    if (position2.x <= -1920)
        position2.x = 1920;
    if (position2_bis.x <= -1920)
        position2_bis.x = 1920;
    if (position3.x <= -1920)
        position3.x = 1920;
    if (position_bis.x <= -1920)
        position_bis.x = 1920;
    if (position_bis2.x <= -1920)
        position_bis2.x = 1920;
    if (position3_bis.x <= -3049)
        position3_bis.x = 3049;
    position.x -= 3.5;
    position2.x -= 0.8;
    position2_bis.x -= 0.8;
    position3.x -= 0.7;
    position3_bis.x -= 0.7;
    position_bis.x -= 2.5;
    position_bis2.x -= 2.5;
    sfSprite_setPosition(bckgrnd[0]->sprite, position);
    sfSprite_setPosition(bckgrnd[2]->sprite, position2);
    sfSprite_setPosition(bckgrnd[7]->sprite, position2_bis);
    sfSprite_setPosition(bckgrnd[1]->sprite, position_bis);
    sfSprite_setPosition(bckgrnd[6]->sprite, position_bis2);
    sfSprite_setPosition(bckgrnd[3]->sprite, position3);
    sfSprite_setPosition(bckgrnd[8]->sprite, position3_bis);
}

void move_obstacles(game_object *obstacle)
{
    sfVector2f position = sfSprite_getPosition(obstacle->sprite);

    position.x -= 2.5;
    sfSprite_setPosition(obstacle->sprite, position);
}

int move_rect(int rect_left)
{
    if (rect_left == 0) {
        rect_left = 60;
    } else {
       rect_left = 0;
    }
    return (rect_left);
}
