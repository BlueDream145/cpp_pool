/*
** EPITECH PROJECT, 2019
** Admiral.cpp
** File description:
** @epitech.eu
*/

#include "Admiral.hpp"

Federation::Starfleet::Admiral::Admiral(std::string name)
{
    const char *fpart = "Admiral ";
    const char *spart = " ready for action.";

    this->_name = name;
    this->movePtr = &Federation::Starfleet::Ship::move;
    this->firePtr = &Federation::Starfleet::Ship::fire;
    std::cout << fpart << this->_name << spart << std::endl;
}

Federation::Starfleet::Admiral::~Admiral()
{
}

bool Federation::Starfleet::Admiral::Admiral::move(Federation::Starfleet::Ship *ship, Destination d)
{
    return (ship->*movePtr)(d);
}

void Federation::Starfleet::Admiral::Admiral::fire(Federation::Starfleet::Ship *ship, Borg::Ship *target)
{
    const char *fpart = "On order from Admiral ";
    const char *spart = ":";

    std::cout << fpart << this->_name << spart << std::endl;
    (ship->*firePtr)(target);
}