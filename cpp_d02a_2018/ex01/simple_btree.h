/*
** EPITECH PROJECT, 2019
** simple_btree.h
** File description:
** @epitech.eu
*/

#ifndef SIMPLE_BTREE_H_
	#define SIMPLE_BTREE_H_

    #include <stdbool.h>

    typedef struct	s_node
    {
        double value;
        struct s_node *left;
        struct s_node *right;
    } node_t;

    typedef node_t *tree_t;

    // Use

    bool btree_is_empty(tree_t tree);
    unsigned int btree_get_size(tree_t tree);
    unsigned int btree_get_depth(tree_t tree);

    // Edit

    bool btree_create_node(tree_t *root_ptr, double value);
    bool btree_delete(tree_t *root_ptr);

    // Access

    double btree_get_max_value(tree_t tree);
    double btree_get_min_value(tree_t tree);

#endif /* !SIMPLE_BTREE_H_ */