/*
** EPITECH PROJECT, 2019
** Buzz.cpp
** File description:
** @epitech.eu
*/

#include <iostream>

#include "Buzz.hpp"

Buzz::Buzz(std::string const & name, std::string const & filename) : Toy(BUZZ, name, filename)
{
}

Buzz::Buzz(Buzz const & buzz) : Toy(buzz)
{
}

Buzz::~Buzz()
{
}

bool Buzz::speak(const std::string message)
{
    const char *bu = "BUZZ: ";

	std::cout << bu;
	return(Toy::speak(message));
}

bool Buzz::speak_es(const std::string message)
{
    const char *bu = "BUZZ: ";
    const char *senorita = " senorita \"";
    const char *ssenorita = "\" senorita";

	std::cout << bu << name << senorita << message << ssenorita << std::endl;
	return true;
}
