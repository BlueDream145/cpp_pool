/*
** EPITECH PROJECT, 2019
** Cure.cpp
** File description:
** @epitech.eu
*/

#include "Cure.hpp"

static const char *cure = "cure";

Cure::Cure() : AMateria(cure)
{
}

Cure::Cure(Cure const & cure) : AMateria(cure)
{
    this->xp = cure.xp;
}

Cure::~Cure() {
}

AMateria * Cure::clone() const
{
    return (new Cure(*this));
}

void Cure::effect(ICharacter & target)
{
    const char *heals = "* heals ";
    const char *wounds = "'s wounds *";

    speak(std::string(heals) + target.getName() + wounds);
}