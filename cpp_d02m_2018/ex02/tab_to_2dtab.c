/*
** EPITECH PROJECT, 2019
** tab_to_2dtab.c
** File description:
** @epitech.eu
*/

#include <stdlib.h>
#include <stdio.h>

void tab_to_2dtab(const int *tab, int length, int width, int ***res)
{
    int **tmp = malloc(sizeof(int *) * length);
    int val = 0;

    for (int x = 0; x < length; x++) {
        tmp[x] = malloc(sizeof(int) * width);
        for (int y = 0; y < width; y++){
            tmp[x][y] = tab[val];
            val++;
        }
    }
    *res = tmp;
}