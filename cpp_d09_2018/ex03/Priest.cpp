/*
** EPITECH PROJECT, 2019
** Priest.cpp
** File description:
** @epitech.eu
*/

#include "Priest.hpp"

Priest::Priest(std::string const & _name, int _level)
{
    const char *enter = "enters in the order";
    const char *defaultWeaponClose = "spirit explosion";
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
    this->costPv = baseCostPv;
    this->restorePm = baseRestorePm;
    this->costPm = baseCostPm;

    this->Range = Character::CLOSE;
    this->weaponClose = std::string(defaultWeaponClose);
    this->weaponRange = std::string(defaultWeaponRange);
    this->bonusCloseAttack = &Priest::force;
    this->bonusRangeAttack = &Priest::force;
    this->bonusRestorePm = &Priest::bonusNull;

    speak(enter);
}

Priest::~Priest()
{

}

int Priest::CloseAttack()
{
    const char *out = "out of power";
    const char *strikes = "uses a ";

    if (actionCost(this->costClose)) {
        speak(std::string(strikes) + weaponClose);
        return(this->atkClose + this->*bonusCloseAttack);
    }
    speak(out);
    return(0);
}

void Priest::Heal()
{
    const char *out = "out of power";
    const char *potion = "casts a little heal spell";

    if (actionCost(this->costPv)) {
        changePv(this->restorePv);
        speak(potion);
        return;
    }
    speak(out);
}