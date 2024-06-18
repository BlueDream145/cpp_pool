/*
** EPITECH PROJECT, 2019
** droid.cpp
** File description:
** @epitech.eu
*/

#include "Droid.hpp"

Droid::Droid(std::string id) : _id(id), _energy(50), _attack(25), _toughness(15) 
{
    const char *standby = "Standing by";
    const char *activated = "Activated";

    this->_status = new std::string(standby);
    this->speak_silent(activated);
}

Droid::Droid(Droid const & droid) : _id(droid._id), _energy(droid._energy), _attack(droid._attack), _toughness(droid._toughness)
{
    const char *standby = "Standing by";
    const char *activated = "Activated, Memory Dumped";

    if (droid._status)
        this->_status = new std::string(*(droid._status));
    else
        this->_status = new std::string(standby);
    speak(activated);
}

Droid::~Droid()
{
    const char *destroyed = "Destroyed";

    if (this->_status)
        delete this->_status;
    this->speak_silent(destroyed);
}

// Get Data

std::string Droid::getId() const
{
    return(this->_id);
}

size_t Droid::getEnergy() const
{
    return(this->_energy);
}

size_t Droid::getAttack() const
{
    return(this->_attack);
}

size_t Droid::getToughness() const
{
    return(this->_toughness);
}

std::string *Droid::getStatus() const
{
    return(this->_status);
}

// Set Data

void Droid::setId(std::string id)
{
    this->_id = id;
}

void Droid::setEnergy(size_t energy)
{
    this->_energy = energy;
}

void Droid::setStatus(std::string *status)
{
    this->_status = status;
}

// Functions

void Droid::speak(std::string message) {
    const char *droid = "Droid '";
    const char *separator = "' ";

    std::cout << droid << this->_id << separator << message << std::endl;
}

void Droid::speak_silent(std::string message) {
    const char *droid = "Droid '";
    const char *separator = "' ";

    std::cout << droid << this->_id << separator << message << std::endl;
}

// Operators

Droid& Droid::operator=(Droid const & droid)
{
    this->_id = droid._id;
    this->_energy = droid._energy;
    delete this->_status;
    this->_status = new std::string(*(droid._status));
    return(*this);
}

bool Droid::operator==(Droid const & droid) const
{
    return this->_id == droid._id &&
    this->_energy == droid._energy &&
    this->_attack == droid._attack &&
    this->_toughness == droid._toughness &&
    *this->_status == *(droid._status);
}

bool Droid::operator!=(Droid const & droid) const
{
    return!(*this == droid);
}

Droid& Droid::operator<<(size_t & energy)
{
    const int energyMax = 100;

    if (this->_energy < energyMax) {
        int take = std::min(energyMax - this->_energy, energy);
        this->_energy += take;
        energy -= take;
    }
    return(*this);
}

std::ostream & operator<<(std::ostream & os, const Droid & droid) {
    const char *_droid = "Droid '";
    const char *separator = "', ";
    size_t energyMax = 100;

    if (droid.getEnergy() > energyMax)
        return(os << _droid << droid.getId() << separator << *(droid.getStatus()) << ", 100");
    else
        return(os << _droid << droid.getId() << separator << *(droid.getStatus()) << ", " << droid.getEnergy());
}