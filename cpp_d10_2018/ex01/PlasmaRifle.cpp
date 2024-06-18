/*
** EPITECH PROJECT, 2019
** PlasmaRifle.cpp
** File description:
** @epitech.eu
*/

#include "PlasmaRifle.hpp"

static const char *rifle = "Plasma Rifle";

PlasmaRifle::PlasmaRifle() : AWeapon(rifle, 5, 21)
{
}

PlasmaRifle::~PlasmaRifle()
{

}

void PlasmaRifle::attack() const
{
    const char *piou = "* piouuu piouuu piouuu *";

    std::cout << piou << std::endl;
}