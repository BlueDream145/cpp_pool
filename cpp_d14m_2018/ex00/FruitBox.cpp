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
    FruitNode *tmp;
    FruitNode *elem;
    int nb = 1;

    if (nb > this->_size)
      return(false);
    if (_header == NULL)
    {
        _header = new FruitNode;
        _header->content = fruit;
        _header->next = NULL;
        this->_count++;
        return(true);
    }
    tmp = _header;
    while (tmp->next != NULL)
    {
        if ((tmp->content == fruit) || (nb >= _size))
            return(false);
        nb++;
        tmp = tmp->next;
    }
    if (nb >= _size)
        return(false);
    if (tmp->content == fruit)
        return (false);
    elem = new FruitNode;
    elem->content = fruit;
    elem->next = NULL;
    tmp->next = elem;
    _count++;
    return(true);
}

Fruit *FruitBox::pickFruit()
{
    FruitNode *tmp;
    Fruit *f;

    if (this->_header == NULL)
        return(NULL);
    f = this->_header->content;
    tmp = _header;
    _header = _header->next;
    delete tmp;
    _count--;
    return(f);
}

FruitNode *FruitBox::head() const
{
    return(this->_header);
}