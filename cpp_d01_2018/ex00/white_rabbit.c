/*
** EPITECH PROJECT, 2019
** white_rabbit.c
** File description:
** @epitech.eu
*/

#include "stdlib.h"
#include "stdio.h"

int follow_the_white_rabbit(void)
{
    int number = 0;
    int seed = 0;

    while (number != 37 && seed < 397 && number != 1) {
        number = (random() % 37) + 1;
        if (number == 13 || (number >= 34 && number != 37))
            printf("right\n");
        else if (number == 26 || (number % 8) == 0)
            printf("backward\n");
        if ((number >= 4 && number <= 6) || (number >= 17 && number <= 21)
            || number == 28)
            printf("left\n");
        else if (number == 23 || number == 15 || number == 10)
            printf("forward\n");
        seed += number;
    }
    printf("RABBIT!!!\n");
    return(seed);
}