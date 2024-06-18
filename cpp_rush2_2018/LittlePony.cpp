/*
** EPITECH PROJECT, 2019
** LittlePony.cpp
** File description:
** @epitech.eu
*/

#include <iostream>

#include "LittlePony.hpp"

LittlePony::LittlePony(std::string const &name) : Toy(name)
{
}

LittlePony::~LittlePony()
{
}

void LittlePony::isTaken()
{
    const char *yo = "yo man";

  std::cout << yo << std::endl;
}
