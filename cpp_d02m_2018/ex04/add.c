/*
** EPITECH PROJECT, 2019
** add.c
** File description:
** @epitech.eu
*/

#include "castmania.h"

int normal_add(int a, int b)
{
    int result = a + b;
    return (result);
}

int absolute_add(int a, int b)
{
    if (a < 0)
        a *= -1;
    if (b < 0)
        b *= -1;
    return (normal_add(a, b));
}

void exec_add(addition_t *operation)
{
    if (operation->add_type == NORMAL)
        operation->add_op.res = normal_add(operation->add_op.a, operation->add_op.b);
    else if (operation->add_type == ABSOLUTE)
        operation->add_op.res = absolute_add(operation->add_op.a, operation->add_op.b);
}