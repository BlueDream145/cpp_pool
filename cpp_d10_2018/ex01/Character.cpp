/*
** EPITECH PROJECT, 2019
** Character.cpp
** File description:
** @epitech.eu
*/

#include "Character.hpp"

Character::Character(std::string _name)
{
    this->name = _name;
    this->ap = 40;

}

Character::~Character()
{
}

void Character::recoverAP()
{
    this->ap += 10;
    if (this->ap > 40)
        ap = 40;
}

void Character::equip(AWeapon *weapon)
{
    this->weapon = weapon;
}

void Character::attack(AEnemy *enemy)
{
    const char *attacks = " attacks ";
    const char *with = " with a ";

    if (!this->weapon || !enemy)
        return;
    if (this->action(this->weapon->getAPCost())) {
        std::cout << name << attacks << enemy->getType() << with << weapon->getName() << std::endl;
        this->weapon->attack();
        enemy->takeDamage(this->weapon->getDamage());
        if (enemy->getHP() <= 0)
            delete enemy;
    }
}

bool Character::action(int val)
{
    if (this->ap >= val) {
        this->ap -= val;
        return(true);
    }
    return(false);
}

std::string const & Character::getName() const
{
    return(this->name);
}

int Character::getAp() const
{
    return(this->ap);
}

AWeapon *Character::getWeapon() const
{
    return(this->weapon);
}

std::ostream & operator<<(std::ostream & os, Character const & perso)
{
    const char *has = " has ";
    const char *sap = " AP and ";
    const char *wields = "wields a ";
    const char *unarmed = "is unarmed";

    os << perso.getName() <<  has << perso.getAp() << sap;
    if (perso.getWeapon())
        os << wields << perso.getWeapon()->getName();
    else
        os << unarmed;
    os << std::endl;
    return(os);
}
