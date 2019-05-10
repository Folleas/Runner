/*
** EPITECH PROJECT, 2019
** My_runner
** File description:
** Functions that manage map
*/

#include "../include/my_runner.h"

void *read_map(char *fp, char **map)
{
    FILE *input;
    size_t len = 0;
    ssize_t read = 0;
    int i = 0;

    input = fopen(fp, "r");
    if (input == NULL) {
        return (NULL);
    }
    while ((read = getline(&map[i], &len, input)) != -1)
        i++;
    fclose(input);
    return (NULL);
}

int check_map(char **map)
{
    int i = 0;
    int nb_obs = 0;

    for (int j = 0; j != 2; j++) {
        while (map[j][i] != '\0') {
            if (map[j][i] == 'x')
                nb_obs += 1;
            i += 1;
        }
        i = 0;
    }
    return (nb_obs);
}

sfVector2f *get_obs_pos(char *map[2], int length, int nb_obs)
{
    sfVector2f *pos_obs = malloc(sizeof(sfVector2f) * nb_obs);
    int u = 0;

    for (int j = 0; j != 2; j++) {
        for (int i = 0; i != (length * 2); i++) {
            if (map[j][i] == 'x') {
                pos_obs[u].x = (i * 100) + 1920;
                pos_obs[u].y = 630 + (j * 150);
                u++;
            }
        }
    }
    return (pos_obs);
}

sfVector2f *obscl_appr(char *fp, int *nb_obs)
{
    char *map[2];

    map[0] = NULL;
    map[1] = NULL;
    read_map(fp, map);
    nb_obs[0] = check_map(map);
    return (get_obs_pos(map, my_strlen(map[0]), nb_obs[0]));
}


