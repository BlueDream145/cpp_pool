/*
** EPITECH PROJECT, 2019
** FruitNode.hpp
** File description:
** @epitech.eu
*/

#ifndef FRUITNODE_HPP_
	#define FRUITNODE_HPP_

    #include "Fruit.hpp"

    class FruitNode {
        public:
            Fruit *content;
            FruitNode *next;
    };

#endif /* !FRUITNODE_HPP_ */