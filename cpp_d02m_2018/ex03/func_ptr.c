/*
** EPITECH PROJECT, 2019
** func_ptr.c
** File description:
** @epitech.eu
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

#include "func_ptr_enum.h"

void print_42(const char *str)
{
    if (str == NULL)
        str = NULL;
    printf("42\n");
}

void print_normal(const char *str)
{
    printf("%s\n", str);
}

void print_reverse(const char *str)
{
    int len = strlen(str) - 1;

    for (; len > 0; len--)
        printf("%c", str[len]);
    printf("\n");
}

void print_upper(const char *str)
{
    const char start_lower = 'a';
    const char end_lower = 'z';

    for (int i = 0; str[i]; i++)
        if (str[i] >= start_lower &&
            str[i] <= end_lower)
            printf("%c", (str[i] - 32));
        else
            printf("%c", str[i]);
    printf("\n");
}

void (*handler[4])(const char*) = {print_normal,
    print_reverse,
    print_upper,
    print_42};

void do_action(action_t action, const char *str)
{
    handler[action](str);
}