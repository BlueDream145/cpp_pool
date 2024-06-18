/*
** EPITECH PROJECT, 2019
** AWeapon.cpp
** File description:
** @epitech.eu
*/

#include "AWeapon.hpp"

AWeapon::AWeapon(std::string const & _name, int _cost, int _dmg)
{
    this->name = _name;
    this->apCost = _cost;
    this->damage = _dmg;
}

AWeapon::~AWeapon()
{
}

std::string const & AWeapon::getName() const
{
    return(this->name);
}

int AWeapon::getAPCost() const
{
    return(this->apCost);
}

int AWeapon::getDamage() const
{
    return(this->damage);
}