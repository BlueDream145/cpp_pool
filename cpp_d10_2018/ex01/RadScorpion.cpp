/*
** EPITECH PROJECT, 2019
** RadScorpion.cpp
** File description:
** @epitech.eu
*/

#include <iostream>

#include "RadScorpion.hpp"

static const char *radScorpion = "RadScorpion";

RadScorpion::RadScorpion() : AEnemy(80, radScorpion)
{
    const char *click = "* click click click *";

    std::cout << click << std::endl;
}

RadScorpion::~RadScorpion()
{
    const char *sprotch = "* SPROTCH *";

    std::cout << sprotch << std::endl;
}