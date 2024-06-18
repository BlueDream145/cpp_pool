/*
** EPITECH PROJECT, 2019
** KoalaSteroid.cpp
** File description:
** @epitech.eu
*/

#include "KoalaSteroid.hpp"

KoalaSteroid::KoalaSteroid()
{
}

KoalaSteroid::~KoalaSteroid()
{
}

std::string KoalaSteroid::getName() const
{
    const char *steroid = "KoalaSteroid";

    return(steroid);
}

std::string KoalaSteroid::beMined(IMiningLaser* laser) const
{
    (void)laser;
    return("");
}

std::string KoalaSteroid::beMined(DeepCoreMiner* laser) const
{
    const char *zazium = "Zazium";

    (void)laser;
    return(zazium);
}

std::string KoalaSteroid::beMined(StripMiner* laser) const
{
    const char *koalite = "Koalite";

    (void)laser;
    return(koalite);
}