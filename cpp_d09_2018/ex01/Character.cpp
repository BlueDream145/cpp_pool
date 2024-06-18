/*
** EPITECH PROJECT, 2019
** Character.cpp
** File description:
** @epitech.eu
*/

#include <string>
#include <iostream>
#include <sstream>

#include "Character.hpp"

// Static values

static const char *defaultWeaponClose = "wooden stick";
static const char *defaultWeaponRange = "stone";

// Builder / Destructor

Character::Character(std::string const & _name, int _level) : bonusNull(0)
{
    const char *created = "Created";

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
    bonusCloseAttack = &Character::force;
    bonusRangeAttack = &Character::force;
    bonusRestorePm = &Character::bonusNull;

    speak(created);
}

Character::~Character()
{
}

Character::Character() : bonusNull(0)
{
}

// Get Data

std::string const & Character::getName() const
{
    return(this->name);
}

int Character::getLvl() const
{
    return(this->lvl);
}

int Character::getPv() const
{
    return(this->pv);
}

int Character::getPower() const
{
    return(this->pm);
}

int Character::getForce() const
{
    return(this->force);
}

int Character::getEndurance() const
{
    return(this->endurance);
}

int Character::getIntelligence() const
{
    return(this->intelligence);
}

int Character::getEsprit() const
{
    return(this->esprit);
}

int Character::getAgilite() const
{
    return(this->agilite);
}

// Set

void Character::changePv(int value) {
    this->pv += value;
    if (this->pv < 0)
        this->pv = 0;
    else if (this->pv > lifeMax)
        this->pv = lifeMax;
}

void Character::changePm(int value) {
    this->pm += value;
    if (this->pm < 0)
        this->pm = 0;
    else if (this->pm > movMax)
        this->pm = movMax;
}

// Actions

int Character::CloseAttack()
{
    const char *out = "out of power";
    const char *strikes = "strikes with a ";

    if (actionCost(this->costClose)) {
        speak(std::string(strikes) + weaponClose);
        return(this->atkClose + this->*bonusCloseAttack);
    }
    speak(out);
    return(0);
}

int Character::RangeAttack()
{
    const char *out = "out of power";
    const char *launch = "tosses a ";

    if (actionCost(this->costRange)) {
        speak(std::string(launch) + weaponRange);
        return(this->atkRange + this->*bonusRangeAttack);
    }
    speak(out);
    return(0);
}

void Character::Heal()
{
    const char *out = "out of power";
    const char *potion = "takes a potion";

    if (actionCost(this->costPv)) {
        changePv(this->restorePv);
        speak(potion);
        return;
    }
    speak(out);
}

void Character::RestorePower()
{
    const char *out = "out of power";
    const char *eats = "eats";

    if (actionCost(this->costPm)) {
        changePm(this->restorePm + this->*bonusRestorePm);
        speak(eats);
        return;
    }
    speak(out);
}

void Character::TakeDamage(int damage)
{
    const char *takes = "takes ";
    const char *damages = " damage";
    const char *out = "out of combat";

    if (damage >= 0) {
        changePv(-damage);
        if (this->pv == 0)
            speak(out);
        else
            speak(std::string(takes) + int_to_string(damage) + damages);
    }
}

bool Character::actionCost(int cost)
{
    if (this->pm >= cost) {
        changePm(-cost);
        return(true);
    }
    return(false);
}

void Character::speak(std::string message) const
{
    std::cout << name << " " << message << std::endl;
}

std::string int_to_string(int n)
{
    std::ostringstream o;
    o << n;
    return(o.str());
}