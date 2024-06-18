/*
** EPITECH PROJECT, 2019
** Lemon.cpp
** File description:
** @epitech.eu
*/

#include "Lemon.hpp"

Lemon::Lemon() : Fruit("lemon", 3)
{
}

Lemon::Lemon(std::string const & name_, int vitamins_)
{
    this->name = name_;
    this->_vitamins = vitamins_;
}

Lemon::~Lemon()
{
}

std::string const & Lemon::getName() const
{
    return(name);
}