/*
** EPITECH PROJECT, 2019
** AsteroKreog.cpp
** File description:
** @epitech.eu
*/

#include "DeepCoreMiner.hpp"
#include "StripMiner.hpp"
#include "AsteroKreog.hpp"

AsteroKreog::AsteroKreog()
{
}

AsteroKreog::~AsteroKreog()
{
}

std::string AsteroKreog::getName() const
{
    const char *astro = "AsteroKreog";

    return(astro);
}

std::string AsteroKreog::beMined(IMiningLaser* laser) const
{
    (void)laser;
    return("");
}

std::string AsteroKreog::beMined(DeepCoreMiner* laser) const
{
    const char *sullite = "Sullite";

    (void) laser;
    return(sullite);
}

std::string AsteroKreog::beMined(StripMiner* laser) const
{
    const char *kreo = "Kreogium";

    (void)laser;
    return(kreo);
}