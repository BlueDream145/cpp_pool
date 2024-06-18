/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** @epitech.eu
*/

#include "menger.h"

static int my_getnbr(char *str)
{
    int val = 0;

    while (*str) {
        if (*str >= '0' && *str <= '9') {
            val *= 10;
            val += *str - '0';
        }
        else
            return(-1);
        str++;
    }
    return(val);
}

int check(int val)
{
    int index = 0;

    for (; val > 1; index++) {
        if ((val % 3) == 0)
            val /= 3;
        else
            return(-1);
    }
    return(index);
}

int main(int ac, char** as)
{
    int size;
    int level;

    if (ac == 3) {
        size = my_getnbr(as[1]);
        level = my_getnbr(as[2]);
        if (size > 0 && level > 0 &&
            check(size) != -1 && level <= check(size))
            menger(level, size, 0, 0);
    }
    return(0);
}