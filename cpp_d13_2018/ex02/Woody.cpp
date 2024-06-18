/*
** EPITECH PROJECT, 2019
** Woody.cpp
** File description:
** @epitech.eu
*/

#include <iostream>

#include "Woody.hpp"

Woody::Woody(std::string const & name, std::string const & filename) : Toy(WOODY, name, filename)
{
}

Woody::Woody(const Woody & woody) : Toy(woody)
{
}

Woody::~Woody()
{
}

bool Woody::speak(const std::string message)
{
    const char *woody = "WOODY: ";

	std::cout << woody;
	return(Toy::speak(message));
}

