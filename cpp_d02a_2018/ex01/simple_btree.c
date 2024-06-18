/*
** EPITECH PROJECT, 2019
** simple_btree.c
** File description:
** @epitech.eu
*/

#include <stdio.h>
#include <stdlib.h>

#include "simple_btree.h"

static unsigned int get_depth(tree_t tree, int n, int val)
{
    unsigned int number;

    if (tree != NULL)
        return(val);
    if (tree->left) {
        if (number = get_depth(tree, n + 1, val)
            < (unsigned int)val)
            val = number;
        return(n);
    } else if (tree->right) {
        if (number = get_depth(tree, n + 1, val)
            < (unsigned int)val)
            val = number;
        return(n);
    }
    return(val);
}

static unsigned int get_len(tree_t tree, int n)
{
    if (tree == NULL)
        return(n);
    if (tree->left)
        return(n + get_len(tree->left, n));
    if (tree->right)
        return(n + get_len(tree->right, n));
    return(n);
}

bool btree_is_empty(tree_t tree)
{
    if (tree == NULL)
        return(true);
    return(false);
}

unsigned int btree_get_size(tree_t tree)
{
    if (tree == NULL)
        return(false);
    return(get_len(tree, 0));
}

unsigned int btree_get_depth(tree_t tree)
{
    unsigned int n = 0;
    unsigned int val = 0;

    if (tree == NULL)
        return(false);
    return(get_depth(tree, n, val));
}

bool btree_create_node(tree_t *root_ptr, double value)
{
    tree_t node;
    tree_t tree;
    tree_t elem = malloc(sizeof(node_t));

    if (elem == NULL)
        return(false);
    elem->value = value;
    elem->left = NULL;
    elem->right = NULL;
    if ((tree = *root_ptr) == NULL)
        *root_ptr = elem;
    else
        while (tree != NULL) {
            node = tree;
            if (value > tree->value)
                tree = tree->right;
            else
                tree = tree->left;
        }
    return(true);
}

bool btree_delete(tree_t *root_ptr)
{
    tree_t tmp = *root_ptr;

    if (!root_ptr)
        return(false);
    if (tmp->right)
        btree_delete(&tmp->right);
    else if (tmp->left)
        btree_delete(&tmp->left);
    free(tmp);
    root_ptr = NULL;
    return(true);
}

static double get_max(tree_t tree, int max)
{
    if (!tree)
        return(max);
    if (tree->value > max)
        max = tree->value;
    if (tree->right)
        return(get_max(tree->right, max));
    if (tree->left)
        return(get_max(tree->left, max));
    return(max);
}

double btree_get_max_value(tree_t tree)
{
    int max = tree->value;

    if (tree == NULL)
        return(false);
    return(get_max(tree, max));
}

static double get_min(tree_t tree, int max)
{
    if (!tree)
        return(max);
    if (tree->value > max)
        max = tree->value;
    if (tree->right)
        return(get_max(tree->right, max));
    if (tree->left)
        return(get_max(tree->left, max));
    return(max);
}

double btree_get_min_value(tree_t tree)
{
    int max = tree->value;

    if (tree == NULL)
        return(false);
    return(get_min(tree, max));
}