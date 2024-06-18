/*
** EPITECH PROJECT, 2019
** TacticalMarine.cpp
** File description:
** @epitech.eu
*/

#include <iostream>

#include "TacticalMarine.hpp"

TacticalMarine::TacticalMarine()
{
    const char *ready = "Tactical Marine ready for battle";

    speak(ready);
}

TacticalMarine::TacticalMarine(TacticalMarine const & marine)
{
    const char *ready = "Tactical Marine ready for battle";

    (void)marine;
    speak(ready);
}

TacticalMarine::~TacticalMarine()
{
    const char *argh = "Aaargh...";

    speak(argh);
}

void TacticalMarine::speak(std::string message) const
{
    std::cout << message << std::endl;
}

ISpaceMarine * TacticalMarine::clone() const
{
    return new TacticalMarine(*this);
}

void TacticalMarine::battleCry() const
{
    const char *plot = "For the holy PLOT!";

    speak(plot);
}

void TacticalMarine::rangedAttack() const
{
    const char *bolter = "* attacks with bolter *";

    speak(bolter);
}

void TacticalMarine::meleeAttack() const
{
    const char *chainsword = "* attacks with chainsword *";

    speak(chainsword);
}
