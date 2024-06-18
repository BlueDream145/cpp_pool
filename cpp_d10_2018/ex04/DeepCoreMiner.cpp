/*
** EPITECH PROJECT, 2019
** DeepCoreMiner.cpp
** File description:
** @epitech.eu
*/

#include <iostream>

#include "DeepCoreMiner.hpp"

DeepCoreMiner::DeepCoreMiner()
{
}

DeepCoreMiner::~DeepCoreMiner()
{
}

void DeepCoreMiner::mine(IAsteroid* asteroid)
{
    const char *mining = "* mining deep ... got ";
    const char *end = "! *";

    std::cout << mining << asteroid->beMined(this) << end << std::endl;
}