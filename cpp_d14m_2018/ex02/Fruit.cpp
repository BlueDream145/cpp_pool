/*
** EPITECH PROJECT, 2019
** Fruit.cpp
** File description:
** @epitech.eu
*/

#include "Fruit.hpp"

Fruit::Fruit()
{
    this->name = "fruit";
    this->_vitamins = 0;
}

Fruit::Fruit(std::string const & name_, int vitamins_)
{
    this->name = name_;
    this->_vitamins = vitamins_;
}

Fruit::~Fruit()
{
}

std::string const & Fruit::getName() const
{
    return(this->name);
}

int Fruit::getVitamins() const
{
    return(this->_vitamins);
}