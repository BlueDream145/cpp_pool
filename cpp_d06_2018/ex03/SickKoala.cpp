/*
** EPITECH PROJECT, 2019
** sickkoala.cpp
** File description:
** @epitech.eu
*/

#include <iostream>
#include <cstring>
#include "SickKoala.hpp"

static const char *fpart = "Mr.";

SickKoala::SickKoala(std::string name)
{
    this->name = name;
}

SickKoala::~SickKoala()
{
    const char *spart = ": Kreooogg!! I'm cuuuured!";

    std::cout << fpart << this->name << spart << std::endl;
}

void SickKoala::poke()
{
    const char *spart = ": Gooeeeeerrk!!";

    std::cout << fpart << this->name << spart << std::endl;
}

bool SickKoala::takeDrug(std::string drug)
{
    const char *spart_1 = ": Mars, and it kreogs!";
    const char *spart_2 = ": And you'll sleep right away!";
    const char *spart_3 = ": Goerkreog!";
    const char *felem = "mars";
    const char *selem = "Buronzand";

    if (strcasecmp(drug.c_str(), felem) == 0) {
        std::cout << fpart << this->name << spart_1 << std::endl;
        return(true);
    } else if (strcmp(drug.c_str(), selem) == 0) {
        std::cout << fpart << this->name << spart_2 << std::endl;
        return(true);
    }
    std::cout << fpart << this->name << spart_3 << std::endl;
    return(false);
}

void SickKoala::overDrive(std::string data)
{
    const char *to_find = "Kreog!";
    const char *to_replace = "1337!";

    while (data.find(to_find) != std::string::npos)
        data.replace(data.find(to_find), strlen(to_find), to_replace);
    std::cout << fpart << this->name << ": " << data << std::endl;
}