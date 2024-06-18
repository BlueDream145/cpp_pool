/*
** EPITECH PROJECT, 2019
** add_mul.c
** File description:
** @epitech.eu
*/

#include <stdio.h>
#include <stdlib.h>

void add_mul_4param(int first, int second, int *sum, int *product)
{
    *sum = first + second;
    *product = first * second;
}

void add_mul_2param(int *first, int *second)
{
    int f = (*first);
    int s = (*second);

    (*first) = f + s;
    (*second) = f * s;
}