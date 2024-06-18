/*
** EPITECH PROJECT, 2019
** PowerFiest.cpp
** File description:
** @epitech.eu
*/

#include <iostream>

#include "PowerFist.hpp"

static const char *powerFist = "Power Fist";

PowerFist::PowerFist() : AWeapon(powerFist, 8, 50)
{
}

PowerFist::~PowerFist()
{
}

void PowerFist::attack() const
{
    const char *bam = "* pschhh... SBAM! *";

    std::cout << bam << std::endl;
}
