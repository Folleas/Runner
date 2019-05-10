/*
** EPITECH PROJECT, 2019
** My_runner
** File description:
** Simple additional functions
*/

#include <my_runner.h>

char *int_to_str(int nbr)
{
    char *str = malloc(sizeof(char) * 5 + 1);
    int count = 0;

    str[5] = '\0';
    for (int i = 10000; i != 0; i /= 10) {
        str[count] = nbr / i + '0';
        nbr %= i;
        count += 1;
    }
    return (str);
}

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}
