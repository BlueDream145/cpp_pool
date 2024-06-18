/*
** EPITECH PROJECT, 2019
** Srocerer.cpp
** File description:
** @epitech.eu
*/

#include <iostream>

#include "Sorcerer.hpp"

Sorcerer::Sorcerer(std::string _name, std::string title)
{
    const char *born = "is born!";
    

    this->name = _name;
    this->title = title;
    speak(born);
}

Sorcerer::~Sorcerer()
{
    const char *died = "is dead. Consequences will never be the same!";

    this->speak(died);
}

std::string Sorcerer::getName() const
{
    return(this->name);
}

std::string Sorcerer::getTitle() const
{
    return(this->title);
}

void Sorcerer::polymorph(Victim const & victim) const
{
    victim.getPolymorphed();
}

void Sorcerer::speak(std::string txt)
{
    std::cout << this->name << ", " << title << ", " << txt << std::endl;
}

std::ostream & operator<<(std::ostream & os, Sorcerer & sorcerer)
{
    return os << "I am " << sorcerer.getName() << ", " << sorcerer.getTitle() << ", and I like ponies!" << std::endl;
}
