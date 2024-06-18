/*
** EPITECH PROJECT, 2019
** StripMiner.cpp
** File description:
** @epitech.eu
*/

#include <iostream>

#include "StripMiner.hpp"

StripMiner::StripMiner()
{
}

StripMiner::~StripMiner()
{
}

void StripMiner::mine(IAsteroid* asteroid)
{
    const char *mining = "* strip mining ... got ";
    const char *end = "! *";

    std::cout << mining << asteroid->beMined(this) << end << std::endl;
}