/*
** EPITECH PROJECT, 2019
** Lime.cpp
** File description:
** @epitech.eu
*/

#include "Lime.hpp"

Lime::Lime() : Lemon()
{
    this->_vitamins = 2;
    this->name = "lime";
}

Lime::~Lime()
{
}


int Lime::getVitamins() const
{
    return(this->_vitamins);
}

std::string Lime::getName() const
{
    return(this->name);
}