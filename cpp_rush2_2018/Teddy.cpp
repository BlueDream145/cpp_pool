/*
** EPITECH PROJECT, 2019
** Teddy.cpp
** File description:
** @epitech.eu
*/

#include <iostream>

#include "Teddy.hpp"

Teddy::Teddy(std::string const &name) : Toy(name)
{
}

Teddy::~Teddy()
{
}

void Teddy::isTaken()
{
    std::cout << "gra hu" << std::endl;
}
