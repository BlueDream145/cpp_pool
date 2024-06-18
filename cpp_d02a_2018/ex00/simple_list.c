/*
** EPITECH PROJECT, 2019
** simple_list.c
** File description:
** @epitech.eu
*/

#include <stdlib.h>
#include <stdio.h>

#include "simple_list.h"

unsigned int list_get_size(list_t list)
{
    unsigned int size = 0;

    for (; list != NULL; size++)
        list = list->next;
    return size;
}

bool_t list_is_empty(list_t list)
{
    if (list == NULL)
        return(TRUE);
    else
        return(FALSE);
}

void list_dump(list_t list)
{
    for (int i = 0; list != NULL; i++) {
        printf("%f\n", list->value);
        list = list->next;
    }
}

bool_t list_add_elem_at_front(list_t *front_ptr, double elem)
{
    list_t temp = malloc(sizeof(list_t));

    if (temp == NULL)
        return(FALSE);
    temp->value = elem;
    temp->next = *front_ptr;
    *front_ptr = temp;
    return(TRUE);
}

bool_t list_add_elem_at_back(list_t *front_ptr, double elem)
{
    node_t *node = malloc(sizeof(list_t));
    list_t tmp;

    if (node == NULL)
        return(FALSE);
    node->value = elem;
    node->next = NULL;
    if (*front_ptr == NULL)
        *front_ptr = node;
    else
    {
        tmp = *front_ptr;
        for (int i; tmp->next != NULL; i++)
            tmp = tmp->next;
        tmp->next = node;
    }
    return(TRUE);
}

bool_t list_add_elem_at_position(list_t *front_ptr, double elem, unsigned int position)
{
    list_t temp = malloc(sizeof(list_t));
    list_t tmp;
    unsigned int i = 0;

    if (position == 0)
        return(list_add_elem_at_front(front_ptr, elem));
    if (temp == NULL)
        return(FALSE);
    temp->value = elem;
    tmp = *front_ptr;
    for (; tmp != NULL; i++) {
        if (i == position) {
            temp->next = tmp->next;
            tmp->next = temp;
            return (TRUE);
        }
        tmp = tmp->next;
    }
    if (i == position)
        list_add_elem_at_back(front_ptr, elem);
    return(TRUE);
}

bool_t list_del_elem_at_front(list_t *front_ptr)
{
    list_t temp;

    if (front_ptr == NULL)
        return(FALSE);
    temp = *front_ptr;
    *front_ptr = (*front_ptr)->next;
    return(TRUE);
}

bool_t list_del_elem_at_back(list_t *front_ptr)
{
    list_t tmp = *front_ptr;
    list_t cach = NULL;

    if (tmp == NULL)
        return(FALSE);
    if ((*front_ptr)->next == NULL) {
        free(*front_ptr);
        return(TRUE);
    }
    tmp = *front_ptr;
    for (int i; tmp->next->next != NULL; i++)
        tmp = tmp->next;
    free(tmp->next);
    tmp->next = NULL;
    return(TRUE);
}

bool_t list_del_elem_at_position(list_t *front_ptr, unsigned int position)
{
    list_t tmp;
    list_t cach;
    unsigned int i = 0;

    if (front_ptr == NULL || position < 0)
        return(FALSE);
    if (position == 0)
        return(list_del_elem_at_front(front_ptr));
    cach = *front_ptr;
    for (; cach->next->next != NULL; i++) {
        if (i == position) {
            tmp = cach->next;
            cach->next = cach->next->next;
            free(tmp);
            return(TRUE);
        }
        cach = cach->next;
    }
    if (i == position)
        return(list_del_elem_at_back(front_ptr));
    return(TRUE);
}

double list_get_elem_at_front(list_t list)
{
    if (list == NULL)
        return(FALSE);
    return(list->value);
}

double list_get_elem_at_back(list_t list)
{
    for (int i = 0; list != NULL; i++)
        list = list->next;
    return(list->value);
}

double list_get_elem_at_position(list_t list, unsigned int position)
{
    for (unsigned int i = 0; list != NULL; i++) {
        if (position == i)
            return(list->value);
        list = list->next;
    }
    return(FALSE);
}

node_t *list_get_first_node_with_value(list_t list, double value)
{
    for (int i = 0; list != NULL; i++) {
        if (list->value == value)
            return(list);
        list = list->next;
    }
    return(FALSE);
}