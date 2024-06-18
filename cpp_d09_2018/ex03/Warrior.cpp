/*
** EPITECH PROJECT, 2019
** Warrior.cpp
** File description:
** @epitech.eu
*/

#include <iostream>

#include "Warrior.hpp"

Warrior::Warrior()
{
}

Warrior::Warrior(std::string const & _name, int _level, std::string weaponName)
{
    const char *fpart = "I'm ";
    const char *spart = " KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG";
    const char *weapon = "hammer";

    this->name = _name;
    this->lvl = _level;
    this->pv = lifeMax;
    this->pm = movMax;
    this->force = defaultForce;
    this->endurance = defaultEndurance;
    this->intelligence = defaultIntelligence;
    this->esprit = defaultEsprit;
    this->agilite = defaultAgilite;
    this->_weaponName = weaponName;

    this->atkClose = baseAtkClose;
    this->costClose = costAtkClose;
    this->atkRange = baseAtkRange;
    this->costRange = costAtkRange;
    this->restorePv = baseRestorePv;
    this->costPv = baseCostPv;
    this->restorePm = baseRestorePm;
    this->costPm = baseCostPm;

    this->Range = Character::CLOSE;
    this->weaponClose = std::string(weapon);
    this->weaponRange = std::string("");
    this->bonusCloseAttack = &Warrior::force;
    this->bonusRangeAttack = &Warrior::force;
    this->bonusRestorePm = &Warrior::bonusNull;

    std::cout << fpart << name << spart << std::endl;
}

Warrior::Warrior(std::string const & name, int lvl)
{
    const char *fpart = "I'm ";
    const char *spart = " KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG";
    const char *weapon = "hammer";

    this->name = name;
    this->lvl = lvl;
    this->force = defaultForce;
    this->endurance = defaultEndurance;
    this->intelligence = defaultIntelligence;
    this->esprit = defaultEsprit;
    this->agilite = defaultAgilite;

    this->atkClose = baseAtkClose;
    this->costClose = costAtkClose;
    this->atkRange = baseAtkRange;
    this->costRange = costAtkRange;
    this->restorePv = baseRestorePv;
    this->costPv = baseCostPv;
    this->restorePm = baseRestorePm;
    this->costPm = baseCostPm;

    this->Range = Character::CLOSE;
    this->weaponClose = std::string(weapon);
    this->weaponRange = std::string("");
    this->bonusCloseAttack = &Warrior::force;
    this->bonusRangeAttack = &Warrior::force;
    this->bonusRestorePm = &Warrior::bonusNull;

    std::cout << fpart << name << spart << std::endl;
}

Warrior::~Warrior()
{
}

// Actions

int Warrior::CloseAttack()
{
    const char *strikes = "strikes with his ";
    const char *out = "out of power";

    if (actionCost(costRange)) {
        speak(strikes);
        this->Range = Character::CLOSE;
    } else
        speak(out);
    return(0);
}

int Warrior::RangeAttack()
{
    const char *intercepts = "intercepts";
    const char *out = "out of power";

    if (actionCost(costRange)) {
        speak(intercepts);
        Range = Character::CLOSE;
    } else
        speak(intercepts);
    return(0);
}