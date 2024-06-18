/*
** EPITECH PROJECT, 2019
** AEnemy.cpp
** File description:
** @epitech.eu
*/

#include "AEnemy.hpp"

AEnemy::AEnemy(int _hp, std::string const & _type)
{
    this->hp = _hp;
    this->type = _type;
}

AEnemy::~AEnemy()
{
}

std::string const & AEnemy::getType() const
{
    return(this->type);
}

int AEnemy::getHP() const
{
    return(this->hp);
}

void AEnemy::takeDamage(int dmg)
{
    if (dmg > 0)
        hp -= dmg;
}