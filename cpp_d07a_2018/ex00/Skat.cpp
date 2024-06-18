/*
** EPITECH PROJECT, 2019
** skat.cpp
** File description:
** @epitech.eu
*/

#include "Skat.hpp"

Skat::Skat(std::string const& name, int paks)
{
    this->_name = name;
    this->_stimPaks = paks;
}

Skat::Skat(std::string const& name)
{
    this->_name = name;
    this->_stimPaks = 15;
}

Skat::Skat(int paks)
{
    this->_name = "bob";
    this->_stimPaks = paks;
}

Skat::Skat()
{
    this->_name = "bob";
    this->_stimPaks = 15;
}

Skat::~Skat()
{

}

int& Skat::stimPaks()
{
    return(this->_stimPaks);
}

const std::string& Skat::name() const
{
    return(this->_name);
}

void Skat::shareStimPaks(int nb, int& stock)
{
    const char *exch = "Keep the change.";
    const char *noexch = "Don't be greedy";

    if (nb <= this->_stimPaks) {
        stock += nb;
        this->_stimPaks -= nb;
        std::cout << exch << std::endl;
    }
    else
        std::cout << noexch << std::endl;
}

void Skat::addStimPaks(unsigned int nb)
{
    const char *add = "Hey boya, did you forget something ?";

    if (nb == 0)
        std::cout << add << std::endl;
    else
        this->_stimPaks += nb;
}

void Skat::useStimPaks()
{
    const char *not_enough = "Mediiiiiic";
    const char *took = "Time to kick some ass and chew bubble gum.";

    if (this->_stimPaks == 0)
        std::cout << not_enough << std::endl;
    else {
        this->_stimPaks -= 1;
        std::cout << took << std::endl;
    }
}

void Skat::status() const
{
    const char *fpart = "Soldier ";
    const char *spart = " reporting ";
    const char *tpart = " stimpaks remaining sir !";

    std::cout << fpart << this->_name << spart
        << this->_stimPaks << tpart << std::endl;
}