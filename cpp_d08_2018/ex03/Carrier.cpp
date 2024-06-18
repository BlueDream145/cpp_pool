/*
** EPITECH PROJECT, 2019
** carrier.cpp
** File description:
** @epitech.eu
*/

#include "Carrier.hpp"

static int energy_max = 600;
static int energy_malus = 10;
static int droids_max = 5;
static int speed_default = 100;
static int speed_malus = 10;

Carrier::Carrier(std::string id) : id(id), energy(300), attack(100), toughness(90)
{
    droids = new Droid*[droids_max];
    for (int i = 0; i < droids_max; i++)
        droids[i] = NULL;
}

Carrier::~Carrier()
{
    for (int i = 0; i < droids_max; i++)
        if (droids[i])
            delete droids[i];
}

std::string Carrier::getId() const
{
    return(id);
}

size_t Carrier::getEnergy() const
{
    return(energy);
}

size_t Carrier::getAttack() const
{
    return(attack);
}

size_t Carrier::getToughness() const
{
    return(toughness);
}

size_t Carrier::getSpeed() const
{
    int nb = getNbDroids();
    if (nb)
        return(speed_default - nb * speed_malus);
    return(0);
}

size_t Carrier::getNbDroids() const
{
    int len = 0;
    for (int i = 0; i < droids_max; i++)
        if (droids[i])
            len++;
    return(len);
}

void Carrier::setId(std::string id)
{
    this->id = id;
}

void Carrier::setEnergy(size_t energy)
{
    this->energy = energy;
}

Droid *&Carrier::operator[](int position) const
{
    return(droids[position]);
}

bool Carrier::operator()(int x, int y)
{
    size_t cost = (std::abs(x) + std::abs(y))
        * (energy_malus + getNbDroids());
    if (cost < energy) {
        energy -= cost;
        if (getSpeed() != 0)
            return(true);
    }
    else
        energy = 0;
    return(false);
}

Carrier &Carrier::operator <<(size_t& energy)
{
    if (this->energy < energy_max) {
        int take = std::min(energy_max - this->energy, energy);
        this->energy += take;
        energy -= take;
    }
    return *this;
}

Carrier &Carrier::operator <<(Droid* droid)
{
    int i;
    for (i = 0; i < droids_max; i++) {
        if (!droids[i]) {
            droids[i] = droid;
            return *this;
        }
    }
    return *this;
}

Carrier &Carrier::operator >>(Droid* droid)
{
    for (int i = 0; i < droids_max; i++)
        if (droids[i]) {
            droid = droids[i];
            droids[i] = NULL;
            return(*this);
        }
    return(*this);
}

Carrier &Carrier::operator ~()
{
    return(*this);
}

std::ostream & operator<<(std::ostream &os, Carrier const & carrier)
{
    os << "Carrier '" << carrier.getId() << "' Droid(s) on-board:" << std::endl;
    for (int i = 0; i < droids_max; i++) {
        os << "[" << i << "] : ";
        if (carrier[i])
            os << carrier[i];
        else
            os << "Free";
        os << std::endl;
    }
    return os;
}