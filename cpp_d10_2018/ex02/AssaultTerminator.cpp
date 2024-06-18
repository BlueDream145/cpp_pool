/*
** EPITECH PROJECT, 2019
** AssaultTerminator.cpp
** File description:
** @epitech.eu
*/

#include <iostream>

#include "AssaultTerminator.hpp"

AssaultTerminator::AssaultTerminator()
{
    const char *teleport = "* teleports from space *";

    speak(teleport);
}

AssaultTerminator::AssaultTerminator(AssaultTerminator const & marine)
{
    const char *teleport = "* teleports from space *";

    (void)marine;
    speak(teleport);
}

AssaultTerminator::~AssaultTerminator() {
    const char *beBack = "I'll be back...";

    std::cout << beBack << std::endl;
}

void AssaultTerminator::speak(std::string message) const
{
    std::cout << message << std::endl;
}

ISpaceMarine * AssaultTerminator::clone() const
{
    return new AssaultTerminator(*this);
}

void AssaultTerminator::battleCry() const
{
    const char *unclean = "This code is unclean. PURIFY IT!";

    speak(unclean);
}

void AssaultTerminator::rangedAttack() const
{
    const char *noth = "* does nothing *";

    speak(noth);
}

void AssaultTerminator::meleeAttack() const
{
    const char *chainfists = "* attacks with chainfists *";

    speak(chainfists);
}
