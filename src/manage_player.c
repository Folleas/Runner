/*
** EPITECH PROJECT, 2018
** My_runner
** File description:
** My_runner's player management functions
*/

#include "my_runner.h"

void player_jump(sfSprite *sprite, sfVector2f pos_player)
{
    if (sfKeyboard_isKeyPressed(sfKeySpace) == sfTrue && (int)pos_player.y >= 630)
        sfSprite_move(sprite, (sfVector2f){0, -3});
    else if (sfKeyboard_isKeyPressed(sfKeySpace) == sfFalse && (int)pos_player.y < 780)
        sfSprite_move(sprite, (sfVector2f){0, 3});
}

int collision(sfVector2f obscl_pos, sfVector2f pos_player, int size_obscl, int size_player)
{
    if (pos_player.x >= obscl_pos.x && pos_player.x + size_player <= obscl_pos.x + size_obscl) {
        if (obscl_pos.y == 780 && pos_player.y >= 780) {
            return (END_SCREEN);
        }
        if (obscl_pos.y == 630 && pos_player.y <= 630) {
            return (END_SCREEN);
        }
    }
    return (GAME);
}

void create_string(sfFont **font, sfText **text)
{
    *font = sfFont_createFromFile("res/police.ttf");
    *text = sfText_create();
    sfText_setOrigin(*text, (sfVector2f){-20, -20});
    sfText_setString(*text, "00000");
    sfText_setFont(*text, *font);
    sfText_setCharacterSize(*text, 75);
}
