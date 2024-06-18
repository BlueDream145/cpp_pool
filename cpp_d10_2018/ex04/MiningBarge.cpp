/*
** EPITECH PROJECT, 2019
** MiningBarge.cpp
** File description:
** @epitech.eu
*/

#include <iostream>

#include "MiningBarge.hpp"

MiningBarge::MiningBarge()
{
    for (int i = 0; i < 4; i++)
        lasers[i] = NULL;
}

MiningBarge::~MiningBarge()
{
}

void MiningBarge::equip(IMiningLaser* laser)
{
    for (int i = 0; i < 4; i++)
        if (!lasers[i]) {
            lasers[i] = laser;
            break;
        }
}

void MiningBarge::mine(IAsteroid* asteroid) const
{
    for (int i = 0; i < 4; i++)
        if (lasers[i])
            lasers[i]->mine(asteroid);
}
