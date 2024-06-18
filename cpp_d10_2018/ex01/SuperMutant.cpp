/*
** EPITECH PROJECT, 2019
** SuperMutant.cpp
** File description:
** @epitech.eu
*/

#include <iostream>

#include "SuperMutant.hpp"

static const char *mutant = "Super Mutant";

SuperMutant::SuperMutant() : AEnemy(170, mutant)
{
    const char *heads = "Gaaah. Me want smash heads!";

    std::cout << heads << std::endl;
}

SuperMutant::~SuperMutant()
{
    const char *argh = "Aaargh...";

    std::cout << argh << std::endl;
}

void SuperMutant::takeDamage(int dmg)
{
    AEnemy::takeDamage(dmg - 3);
}
