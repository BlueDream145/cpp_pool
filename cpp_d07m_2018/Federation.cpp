/*
** EPITECH PROJECT, 2019
** Federation.cpp
** File description:
** @epitech.eu
*/

#include "Federation.hpp"
#include "WarpSystem.hpp"

static const char *fpart = "USS ";

// #Federation - #Starfleet - #Captain

Federation::Starfleet::Captain::Captain(std::string name)
{
    this->_name = name;
}

Federation::Starfleet::Captain::~Captain()
{
}

std::string Federation::Starfleet::Captain::getName()
{
    return(this->_name);
}

int Federation::Starfleet::Captain::getAge()
{
    return(this->_age);
}

void Federation::Starfleet::Captain::setAge(int nb)
{
    this->_age = nb;
}

// #Federation - #Starfleet - #Ensign

Federation::Starfleet::Ensign::Ensign(std::string name)
{
    const char *ensign = "Ensign ";
    const char *orders = ", awaiting orders.";

    this->_name = name;
    std::cout << ensign << name << orders << std::endl;
}

Federation::Starfleet::Ensign::~Ensign()
{
}

void Federation::Starfleet::Ensign::speak(std::string message) {
    const char *ensign = "Ensign ";
    const char *separator = ", ";

    std::cout << ensign << this->_name << separator << message << std::endl;
}

// #Federation - #Starfleet - #Ship

// Builder / Destructor

Federation::Starfleet::Ship::Ship(int len, int width, std::string name, short max, int torpedo)
{
    this->_length = len;
    this->_width = width;
    this->_name = name;
    this->_maxWarp = max;
    this->_home = EARTH;
    this->_location = this->_home;
    this->_shield = 100;
    this->_photonTorpedo = torpedo;
    std::cout << "The ship USS " << this->_name << " has been finished." << std::endl;
    std::cout << "It is " << this->_length << " m in length and " << this->_width << " m in width." << std::endl;
    std::cout << "It can go to Warp " << this->_maxWarp << "!" << std::endl;
}

Federation::Starfleet::Ship::Ship(int length, int width, std::string name, short maxWarp)
{
    this->_length = length;
    this->_width = width;
    this->_name = name;
    this->_maxWarp = maxWarp;
    this->_home = EARTH;
    this->_location = this->_home;
    this->_shield = 100;
    this->_photonTorpedo = 0;
    std::cout << "The ship USS " << this->_name << " has been finished." << std::endl;
    std::cout << "It is " << this->_length << " m in length and " << this->_width << " m in width." << std::endl;
    std::cout << "It can go to Warp " << this->_maxWarp << "!" << std::endl;
}

Federation::Starfleet::Ship::Ship()
{
    Ship(289, 132, "Entreprise", 6, 20);
}

Federation::Starfleet::Ship::~Ship()
{
}

// Functions

void Federation::Starfleet::Ship::promote(Federation::Starfleet::Captain *capt)
{
    const char *new_capt = ": I'm glad to be the captain of the USS ";
    const char *point = ".";

    this->capt = capt;
    std::cout << capt->getName() << new_capt
        << this->_name << point << std::endl;
}

void Federation::Starfleet::Ship::setupCore(WarpSystem::Core *core)
{
    const char *s_setupCore = ": The core is set.";

    this->_core = core;
    std::cout << fpart << this->_name << s_setupCore << std::endl;
}

void Federation::Starfleet::Ship::checkCore()
{
    const char *stable = ": The core is stable at the time.";
    const char *unstable = ": The core is unstable at the time.";

    if (!this->_core)
        return;
    if (this->_core->checkReactor()->isStable())
        std::cout << fpart << this->_name << stable << std::endl;
    else
        std::cout << fpart << this->_name << unstable << std::endl;
}

bool Federation::Starfleet::Ship::move(int warp, Destination d)
{
    if (warp <= this->_maxWarp
        && d != this->_location
        && this->isStable()) {
        this->_location = d;
        return(true);
    } else
        return(false);
}

bool Federation::Starfleet::Ship::move(int warp)
{
    return(move(warp, this->_home));
}

bool Federation::Starfleet::Ship::move(Destination d)
{
    return(move(this->_maxWarp, d));
}

bool Federation::Starfleet::Ship::move()
{
    return(move(this->_maxWarp, this->_home));
}

// Get value


int Federation::Starfleet::Ship::getShield()
{
    return(this->_shield);
}

int Federation::Starfleet::Ship::getPhotonTorpedo()
{
    return(this->_photonTorpedo);
}

Federation::Starfleet::Captain *Federation::Starfleet::Ship::getCaptain()
{
    return(this->_captain);
}

int Federation::Starfleet::Ship::getLength()
{
    return(this->_length);
}

int Federation::Starfleet::Ship::getWidth()
{
    return(this->_width);
}

short Federation::Starfleet::Ship::getMaxWarp()
{
    return(this->_maxWarp);
}

std::string Federation::Starfleet::Ship::getName()
{
    return(this->_name);
}

WarpSystem::Core *Federation::Starfleet::Ship::getCore()
{
    return(this->_core);
}

Destination Federation::Starfleet::Ship::getLocation()
{
    return(this->_location);
}

Destination Federation::Starfleet::Ship::getHome()
{
    return(this->_home);
}

bool Federation::Starfleet::Ship::isStable()
{
    if (this->getCore())
        return(this->getCore()->isStable());
    return(false);
}

// Set Value

void Federation::Starfleet::Ship::setShield(int shield)
{
    this->_shield = shield;
}

void Federation::Starfleet::Ship::setHome(Destination home)
{
    this->_home = home;
}

void Federation::Starfleet::Ship::setCore(WarpSystem::Core *core)
{
    this->_core = core;
}

void Federation::Starfleet::Ship::setLocation(Destination dest)
{
    this->_location = dest;
}

void Federation::Starfleet::Ship::setPhotonTorpedo(int torpedo)
{
    this->_photonTorpedo = torpedo;
}

// Functions

void Federation::Starfleet::Ship::fire(Borg::Ship *target)
{
    return(fire(1, target));
}

void Federation::Starfleet::Ship::fire(int torpedoes, Borg::Ship *target)
{
    if (torpedoes < this->_photonTorpedo) {
        target->stricken(50 * torpedoes);
        this->_photonTorpedo -= torpedoes;
        std::cout << this->_name << ": Firing on target. " << std::to_string(torpedoes) << " torpedoes remaining." << std::endl;
    } else if (this->_photonTorpedo) {
        std::cout << this->_name << ": No more torpedo to fire, "
            << (this->_captain ? this->_captain->getName() : "") << "!" << std::endl;
    } else {
        std::cout << this->_name << ": No enough torpedoes to fire, "
            << (this->_captain ? this->_captain->getName() : "") << "!" << std::endl;
    }
}

void Federation::Starfleet::Ship::stricken(int damage)
{
    this->_shield -= damage;
    if (this->_shield < 0)
        this->_shield = 0;
}

// #Federation - #Ship

// Builder / Destructor

Federation::Ship::Ship(int len,int width, std::string name)
{
    this->_length = len;
    this->_width = width;
    this->_name = name;
    this->_home = VULCAN;
    this->_location = this->_home;
    std::cout << "The independant ship " << this->_name << " just finished its construction." << std::endl;
    std::cout << "It is " << this->_length << " m in length and " << this->_width << " m in width." << std::endl;
}

Federation::Ship::~Ship()
{
}

// Get data

int Federation::Ship::getLength()
{
    return(this->_length);
}

int Federation::Ship::getWidth()
{
    return(this->_width);
}

short Federation::Ship::getMaxWarp()
{
    return(1);
}

std::string Federation::Ship::getName()
{
    return(this->_name);
}

WarpSystem::Core *Federation::Ship::getCore()
{
    return(this->_core);
}

Destination Federation::Ship::getLocation()
{
    return(this->_location);
}

Destination Federation::Ship::getHome()
{
    return(this->_home);
}

bool Federation::Ship::getStable()
{
    return(this->_core->isStable());
}

// Set data

void Federation::Ship::setHome(Destination home)
{
    this->_home = home;
}

void Federation::Ship::setCore(WarpSystem::Core *core)
{
    this->_core = core;
}

void Federation::Ship::setLocation(Destination dest)
{
    this->_location = dest;
}

// Functions

void Federation::Ship::setupCore(WarpSystem::Core *core)
{
    const char *s_setupCore = ": The core is set.";

    this->_core = core;
    std::cout << this->_name << s_setupCore << std::endl;
}

void Federation::Ship::checkCore()
{
    const char *stable = ": The core is stable at the time.";
    const char *unstable = ": The core is unstable at the time.";

    if (!this->_core)
        return;
    if (this->_core->checkReactor()->isStable())
        std::cout << this->_name << stable << std::endl;
    else
        std::cout << this->_name << unstable << std::endl;
}

bool Federation::Ship::move(int warp, Destination d)
{
    if (warp <= this->getMaxWarp()
        && d != this->_location) {
        this->_location = d;
        return(true);
    } else
        return(false);
}

bool Federation::Ship::move(int warp)
{
    return(move(warp, this->_home));
}

bool Federation::Ship::move(Destination d)
{
    return(move(this->getMaxWarp(), d));
}

bool Federation::Ship::move()
{
    return(move(this->getMaxWarp(), this->_home));
}

void Federation::Ship::stricken(int damage)
{
    if (damage == 0)
        damage = 0;
    damage = 0;
    if (this->getCore())
        this->getCore()->setStability(false);
}