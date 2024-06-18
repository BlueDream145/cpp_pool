/*
** EPITECH PROJECT, 2019
** Ice.cpp
** File description:
** @epitech.eu
*/

#include "Ice.hpp"

static const char *ice = "ice";

Ice::Ice() : AMateria(ice)
{
}

Ice::Ice(Ice const & ice) : AMateria(ice)
{
    this->xp = ice.xp;
}

Ice::~Ice()
{
}

AMateria * Ice::clone() const
{
    return(new Ice(*this));
}

void Ice::effect(ICharacter & target)
{
    const char *shoots = "* shoots an ice bolt at ";

    speak(std::string(shoots) + target.getName() + " *");
}
