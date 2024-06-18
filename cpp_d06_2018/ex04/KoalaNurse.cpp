/*
** EPITECH PROJECT, 2019
** koalanurse.cpp
** File description:
** @epitech.eu
*/

#include <fstream>

#include "KoalaNurse.hpp"

static const char *fpart = "Nurse ";

KoalaNurse::KoalaNurse(int val)
{
    this->id = val;
    this->work = false;
}

KoalaNurse::~KoalaNurse()
{
    const char *spart = ": Finally some rest!";

    std::cout << fpart << this->id << spart << std::endl;
}

void KoalaNurse::timeCheck()
{
    const char *swork = ": Time to get to work!";
    const char *ework = ": Time to go home to my eucalyptus forest!";

    if (work == false) {
        std::cout << fpart << this->id << swork << std::endl;
        work = true;
    } else {
        std::cout << fpart << this->id << ework << std::endl;
        work = false;
    }
}

void KoalaNurse::giveDrug(std::string drug, SickKoala *koala)
{
    koala->takeDrug(drug);
}

std::string KoalaNurse::readReport(std::string filename)
{
    const char *spart = ": Kreog! Mr.";
    const char *tpart = " needs a ";
    const char *lpart = "!";
    const char *report = "report";
    std::string koala;
    std::string drug = "";
    std::ifstream file;

    if (filename.substr(filename.find_last_of(".") + 1) == report) {
        koala = filename.substr(0, filename.find("."));
        file.open(filename.c_str());
        if (file.is_open())
            getline(file, drug);
        if (drug != "")
            std::cout << fpart << this->id << spart << koala
                << tpart << drug << lpart << std::endl;
    }
    return(drug);
}