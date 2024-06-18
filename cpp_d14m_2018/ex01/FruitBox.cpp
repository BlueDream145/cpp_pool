/*
** EPITECH PROJECT, 2019
** FruitBox.cpp
** File description:
** @epitech.eu
*/

#include <iostream>

#include "FruitBox.hpp"

FruitBox::FruitBox(int size)
{
    this->_size = size;
    this->_header = NULL;
    this->_count = 0;
}

FruitBox::~FruitBox()
{
}

int FruitBox::nbFruits() const
{
    return(this->_count);
}

bool FruitBox::putFruit(Fruit *fruit)
{
	FruitNode *current = _header;
	FruitNode *node = new FruitNode();
    
    if (fruit == NULL || _count >= _size)
        return (false);
	node->content = fruit;
	if (!_header)
		_header = node;
	else
	{
		if (current->content == fruit)
			return (false);
		while (current->next)
		{
			if (current->content == fruit)
				return (false);
			current = current->next;
		}
		current->next = node;
	}
	_count++;
	return (true);
}

Fruit *FruitBox::pickFruit()
{
    if (this->_header == NULL)
        return(NULL);
    Fruit *tmp = _header->content;
    _header = _header->next;
    _count--;
    return(tmp);
}

FruitNode *FruitBox::head() const
{
    return(this->_header);
}