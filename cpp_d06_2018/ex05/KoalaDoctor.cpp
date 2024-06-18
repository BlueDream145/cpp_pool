/*
** EPITECH PROJECT, 2019
** koaladoctor.cpp
** File description:
** @epitech.eu
*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>

#include "KoalaDoctor.hpp"

static const char *fpart = "Dr.";

KoalaDoctor::KoalaDoctor(std::string name)
{
    const char *spart = ": I'm Dr.";
    const char *tpart = "! How do you kreog?";

    this->name = name;
    this->active = false;
    std::cout << fpart << this->name << spart << name << tpart << std::endl;
}

KoalaDoctor::~KoalaDoctor()
{
    this->name = "";
}

void KoalaDoctor::diagnose(SickKoala *koala)
{
    const std::string drugs[5] = { "mars", "Buronzand", "Viagra",
        "Extasy", "Eucalyptus leaf"};
    const char *spart = ": So what's goerking you Mr.";
    const char *tpart = "?";
    std::string file;
    std::ofstream stream;
    int index = random() % 5;

    std::cout << fpart << this->name << spart << name << tpart << std::endl;
    koala->poke();
    file = koala->getName();
    file += ".report";
    stream.open(file.c_str());
    if (stream.is_open())
        stream << drugs[index];
}

void KoalaDoctor::timeCheck()
{
    const char *swork = ": Time to get to work!";
    const char *ework = ": Time to go home to my eucalyptus forest!";

    if (this->active == false) {
        std::cout << fpart << this->name << swork << std::endl;
        this->active = true;
    } else {
        std::cout << fpart << this->name << ework << std::endl;
        this->active = false;
    }
}

std::string KoalaDoctor::getName()
{
    return(this->name);
}