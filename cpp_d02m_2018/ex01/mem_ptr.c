/*
** EPITECH PROJECT, 2019
** mem_ptr.c
** File description:
** @epitech.eu
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "mem_ptr.h"

void add_str(char *s1, char *s2, char **res)
{
    char *str = malloc(strlen(s1) + strlen(s2));

    if (str == NULL)
        return;
    str = strcat(str, s1);
    str = strcat(str, s2);
    *res = str;
}

void add_str_struct(str_op_t *str_op)
{
    char *str = malloc(strlen(str_op->str1) + strlen(str_op->str2));

    if (str == NULL)
        return;
    str = strcat(str, str_op->str1);
    str = strcat(str, str_op->str2);
    str_op->res = str;
}