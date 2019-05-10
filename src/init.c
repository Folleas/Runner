/*
** EPITECH PROJECT, 2019
** My_runner
** File description:
** Main
*/

#include "my_runner.h"

void init_game(sfClock **clock, sfRenderWindow **window, sfVector2i wndw_size, game_object ***objects, sfFont **font, sfText **text, sfMusic **music)
{
    sfMusic_setLoop(*music, sfTrue);
    *clock = sfClock_create();
    sfMusic_setVolume(*music, 100);
    sfMusic_play(*music);
    init_window(&window[0], "My_Runner", wndw_size.x, wndw_size.y);
    init_rect(&objects[0][4]->rect);
    create_string(&font[0], &text[0]);
}

int main(int ac, char **av)
{
    int nb_obs;
    sfVector2f *obscl_pos;

    if (ac != 2) {
        write(2, "The game only takes 2 arguments, please be sure you checked -h\n", 63);
	return (84);
    }
    if (av[1][1] == 'h') {
        write(2, "You have to pass a map as argument\nExample :\t./my_runner include/map.txt\\
n\nUser Interaction :\nSPACE_BAR:\tJump\n", 112);
	return (84);
    }
    obscl_pos = obscl_appr(av[1], &nb_obs);
    setup(obscl_pos, nb_obs);
    return (0);
}
