/*
** EPITECH PROJECT, 2019
** Borg.cpp
** File description:
** @epitech.eu
*/

#include <string>
#include <iostream>

#include "Borg.hpp"
#include "Federation.hpp"

// #Borg

// Builder / Destructor

Borg::Ship::Ship(int frequency, short repair)
{
    const char *fline = "We are the Borgs. Lower your shields and surrender yourselves unconditionally.";
    const char *sline = "Your biological characteristics and technologies will be assimilated.";
    const char *eline = "Resistance is futile.";
    
    this->_side = 3000;
    this->_maxWarp = 9;
    this->_home = UNICOMPLEX;
    this->_location = this->_home;
    this->_shield = 100;
    this->_weaponFrequency = frequency;
    this->_repair = repair;
    std::cout << fline << std::endl;
    std::cout << sline << std::endl;
    std::cout << eline << std::endl;
}

Borg::Ship::~Ship()
{
}

// Get data

bool Borg::Ship::Ship::isStable()
{
    if (this->getCore())
        return(this->getCore()->isStable());
    return(false);
}

int Borg::Ship::Ship::getShield()
{
    return(this->_shield);
}

int Borg::Ship::Ship::getSide()
{
    return(this->_side);
}

int Borg::Ship::Ship::getWeaponFrequency()
{
    return(this->_weaponFrequency);
}

short Borg::Ship::Ship::getRepair()
{
    return(this->_repair);
}

short Borg::Ship::Ship::getMaxWarp()
{
    return(this->_maxWarp);
}

WarpSystem::Core *Borg::Ship::Ship::getCore()
{
    return(this->_core);
}

Destination Borg::Ship::Ship::getLocation()
{
    return(this->_location);
}

Destination Borg::Ship::Ship::getHome()
{
    return(this->_home);
}

// Set data

void Borg::Ship::setShield(int shield)
{
    this->_shield = shield;
}

void Borg::Ship::setCore(WarpSystem::Core *core)
{
    this->_core = core;
}

void Borg::Ship::setLocation(Destination location)
{
    this->_location = location;
}

void Borg::Ship::setHome(Destination home)
{
    this->_home = home;
}

void Borg::Ship::setWeaponFrequency(int frequency)
{
    this->_weaponFrequency = frequency;
}

void Borg::Ship::setRepair(short repair)
{
    this->_repair = repair;
}

// Functions

void Borg::Ship::setupCore(WarpSystem::Core *core)
{
    this->_core = core;
}

void Borg::Ship::checkCore()
{
    const char *stable = "Everything is in order.";
    const char *unstable = "Critical failure imminent.";

    if (!this->_core)
        return;
    if (this->_core->checkReactor()->isStable())
        std::cout << stable << std::endl;
    else
        std::cout << unstable << std::endl;
}

bool Borg::Ship::move(int warp, Destination d)
{
    if (warp <= this->_maxWarp
        && d != this->_location
        && this->isStable()) {
        this->_location = d;
        return(true);
    } else
        return(false);
}

bool Borg::Ship::move(int warp)
{
    return(move(warp, this->_home));
}

bool Borg::Ship::move(Destination d)
{
    return(move(this->_maxWarp, d));
}

bool Borg::Ship::move()
{
    return(move(this->_maxWarp, this->_home));
}

void Borg::Ship::fire(Federation::Starfleet::Ship *ship)
{
    const char *fpart = "Firing on target with ";
    const char *spart = "GW frequency.";

    ship->stricken(this->_weaponFrequency);
    std::cout << fpart << this->_weaponFrequency << spart << std::endl;
}

void Borg::Ship::fire(Federation::Ship *ship)
{
    const char *fpart = "Firing on target with ";
    const char *spart = "GW frequency.";

    ship->stricken(this->_weaponFrequency);
    std::cout << fpart << this->_weaponFrequency << spart << std::endl;
}

void Borg::Ship::stricken(int val)
{
    this->_shield -= val;
    if (this->_shield < 0)
        this->_shield = 0;
}

void Borg::Ship::repair()
{
    const char *stepRepair = "Begin shield re-initialisation... Done. Awaiting further instructions.";
    const char *stepEnergy = "Energy cells depleted, shield weakening.";

    if (this->_repair > 0) {
        this->_repair--;
        this->_shield = 100;
        std::cout << stepRepair << std::endl;
    } else
        std::cout << stepEnergy << std::endl;

}