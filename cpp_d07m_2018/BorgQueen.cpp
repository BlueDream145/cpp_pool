/*
** EPITECH PROJECT, 2019
** BorgQueen.cpp
** File description:
** @epitech.eu
*/

#include "BorgQueen.hpp"

Borg::BorgQueen::BorgQueen()
{
    this->movePtr = &Borg::Ship::move;
    this->firePtr = &Borg::Ship::fire;
    this->destroyPtr = &Borg::Ship::fire;
}

Borg::BorgQueen::~BorgQueen()
{
}

bool Borg::BorgQueen::move(Borg::Ship* ship, Destination d)
{
    return(ship->*movePtr)(d);
}

void Borg::BorgQueen::fire(Borg::Ship* ship, Federation::Starfleet::Ship* target)
{
    (ship->*firePtr)(target);
}

void Borg::BorgQueen::destroy(Borg::Ship* ship, Federation::Ship* target)
{
    (ship->*destroyPtr)(target);
}