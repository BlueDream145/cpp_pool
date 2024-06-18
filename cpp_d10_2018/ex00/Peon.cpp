/*
** EPITECH PROJECT, 2019
** Peon.cpp
** File description:
** @epitech.eu
*/

#include <iostream>

#include "Peon.hpp"

Peon::Peon(std::string name) : Victim(name)
{
    const char *zog = "Zog zog.";

    std::cout << zog << std::endl;
}

Peon::~Peon()
{
    const char *bleuark = "Bleuark...";

    std::cout << bleuark << std::endl;
}

void Peon::getPolymorphed() const
{
    const char *pony = " has been turned into a pink pony!";

    std::cout << this->name << pony << std::endl;
}