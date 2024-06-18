/*
** EPITECH PROJECT, 2019
** Coconut.cpp
** File description:
** @epitech.eu
*/

#include "Coconut.hpp"

Coconut::Coconut() : Fruit("coconut", 15)
{
}

Coconut::~Coconut()
{
}

std::string const & Coconut::getName() const
{
    return(name);
}