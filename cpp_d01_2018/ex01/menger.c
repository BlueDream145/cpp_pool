/*
** EPITECH PROJECT, 2019
** menger.c
** File description:
** @epitech.eu
*/

#include "menger.h"
#include "stdio.h"

static void process_menger(int level, int div, int abs, int ord)
{
    for (int x = 0; x < 3; x++)
        for (int y = 0; y < 3; y++)
            if (x != 1 || y != 1)
                menger(level - 1, div, x * div + abs, y * div + ord);
}

int menger(int level, int size, int abs, int ord)
{
    int div = size / 3;

    if (level > 0)
        printf("%03d %03d %03d\n", div, div + abs, div + ord);
    if (level > 1)
        process_menger(level, div, abs, ord);
    return(0);
}