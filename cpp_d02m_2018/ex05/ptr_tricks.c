/*
** EPITECH PROJECT, 2019
** ptr_tricks.c
** File description:
** @epitech.eu
*/

#include "ptr_tricks.h"

int get_array_nb_elem(const int *ptr1, const int *ptr2)
{
    int val = ptr2 - ptr1;

    return (val);
}

whatever_t *get_struct_ptr(const int *member_ptr)
{
    whatever_t what;

    return (void*)(member_ptr) - ((void*)(&what.member) - (void*)(&what));
}