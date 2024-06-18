/*
** EPITECH PROJECT, 2019
** mage.cpp
** File description:
** @epitech.eu
*/

#include "Mage.hpp"

Mage::Mage() {

}

Mage::Mage(std::string const & _name, int _level)
{
    const char *teleported = "teleported";
    const char *weapon = "fire ball";

    this->name = _name;
    this->lvl = _level;
    pv = lifeMax;
    pm = movMax;
    force = defaultForce;
    endurance = defaultEndurance;
    intelligence = defaultIntelligence;
    esprit = defaultEsprit;
    agilite = defaultAgilite;

    atkClose = baseAtkClose;
    costClose = costAtkClose;
    atkRange = baseAtkRange;
    costRange = costAtkRange;
    restorePv = baseRestorePv;
    costPv = baseCostPv;
    restorePm = baseRestorePm;
    costPm = baseCostPm;

    Range = Character::CLOSE;
    weaponClose = std::string("");
    weaponRange = std::string(weapon);
    bonusCloseAttack = &Mage::bonusNull;
    bonusRangeAttack = &Mage::esprit;
    bonusRestorePm = &Mage::intelligence;

    this->speak(teleported);
}

Mage::~Mage() {

}

int Mage::RangeAttack()
{
    const char *out = "out of power";
    const char *launch = "launches a ";

    if (actionCost(this->costRange)) {
        speak(std::string(launch) + weaponRange);
        return(this->atkRange + this->*bonusRangeAttack);
    }
    speak(out);
    return(0);
}

int Mage::CloseAttack() {
    const static char *blinks = "blinks";
    const static char *out = "out of power";

    if (actionCost(costClose)) {
        this->speak(blinks);
        Range = Character::RANGE;
        return(0);
    }
    this->speak(out);
    this->RangeAttack();
    return(0);
}

void Mage::RestorePower() {
    const char *out = "out of power";
    const char *eats = "takes a mana potion";

    if (actionCost(this->costPm)) {
        changePm(this->restorePm + this->*bonusRestorePm);
        speak(eats);
        return;
    }
    speak(out);
}