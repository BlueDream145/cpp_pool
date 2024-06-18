/*
** EPITECH PROJECT, 2019
** Victim.cpp
** File description:
** @epitech.eu
*/

#include <iostream>
#include <string>

#include "Victim.hpp"

Victim::Victim(std::string name) : name(name)
{
    const char *victim = "Some random victim called ";
    const char *popped = " just popped!";

    std::cout << victim << name << popped << std::endl;
}

Victim::~Victim()
{
    const char *victim = "Victim ";
    const char *died = " just died for no apparent reason!";

    std::cout << victim << name << died << std::endl;
}

std::string Victim::getName() const
{
    return(name);
}

void Victim::getPolymorphed() const
{
    const char *turned = " has been turned into a cute little sheep!";

    std::cout << name << turned << std::endl;
}

std::ostream & operator<<(std::ostream & os, Victim & victim)
{
    const char *me = "I'm ";
    const char *life = " and i like otters!";

    return os << me << victim.getName() << life << std::endl;
}