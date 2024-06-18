/*
** EPITECH PROJECT, 2019
** Paladin.cpp
** File description:
** @epitech.eu
*/

#include <iostream>
#include <string>
#include "Paladin.hpp"

Paladin::Paladin()
{
}

Paladin::Paladin(std::string const & _name, int _level)
{
    const char *fpart = "I'm ";
    const char *spart = " KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG";
    const char *defaultWeaponClose = "hammer";
    const char *defaultWeaponRange = "fire ball";

    this->name = _name;
    this->lvl = _level;
    this->pv = lifeMax;
    this->pm = movMax;
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
    this->costPv = Priest::baseCostPv;
    this->restorePm = baseRestorePm;
    this->costPm = Mage::baseCostPm;

    this->Range = Character::CLOSE;
    this->weaponClose = std::string(defaultWeaponClose);
    this->weaponRange = std::string(defaultWeaponRange);
    this->bonusCloseAttack = &Paladin::force;
    this->bonusRangeAttack = &Paladin::force;
    this->bonusRestorePm = &Paladin::bonusNull;
    
    std::cout << fpart << name << spart << std::endl;
    speak("teleported");
    speak("enters in the order");
    std::cout << "the light falls on " << name << std::endl;
}

Paladin::~Paladin()
{
}

int Paladin::CloseAttack()
{
    const char *intercepts = "strikes with his ";
    const char *out = "out of power";

    if (actionCost(costRange)) {
        speak(intercepts);
        this->Range = Character::CLOSE;
    } else
        speak(out);
    return(0);
}

int Paladin::RangeAttack() {
    return(Priest::RangeAttack());
}

void Paladin::Heal() {
    Priest::Heal();
}

int Paladin::Intercept() {
    const char *intercept = "intercepts";
    const char *out = "out of power";

    if (actionCost(10)) {
        speak(intercept);
        Range = Character::CLOSE;
    } else
        speak(out);
    return(0);
}