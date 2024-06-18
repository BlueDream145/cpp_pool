/*
** EPITECH PROJECT, 2019
** Banana.cpp
** File description:
** @epitech.eu
*/

#include "Banana.hpp"

Banana::Banana() : Fruit()
{
    this->_vitamins = 5;
    this->name = "banana";
}

Banana::~Banana()
{
}

int	Banana::getVitamins() const
{
    return(this->_vitamins);
}

std::string	Banana::getName() const
{
    return(this->name);
}