/*
** EPITECH PROJECT, 2019
** Toy.cpp
** File description:
** @epitech.eu
*/

#include <iostream>

#include "Toy.hpp"

static const char *toy = "toy";

Toy::Toy() : type(BASIC_TOY), name(toy)
{
}

Toy::Toy(ToyType type, std::string const & name, std::string const & ascii) : type(type), name(name), picture(ascii)
{
}

Toy::Toy(Toy const & toy) : type(toy.type), name(toy.name), picture(toy.picture)
{
}

Toy::~Toy()
{
}

int Toy::getType() const
{
	return(this->type);
}

std::string const & Toy::getName() const
{
	return(this->name);
}

std::string const & Toy::getAscii() const
{
	return(this->picture.data);
}

void Toy::setName(std::string const & name)
{
	this->name = name;
}

bool Toy::setAscii(std::string const & ascii)
{
    if (this->picture.getPictureFromFile(ascii))
        return(true);
	this->error.setType(Error::PICTURE);
	return(false);
}

bool Toy::speak(const std::string message)
{
	std::cout << this->name << " \"" << message << "\"" << std::endl;
	return(true);
}

bool Toy::speak_es(const std::string message)
{
	(void)message;
	this->error.setType(Error::SPEAK);
	return(false);
}

Toy::Error const & Toy::getLastError() const
{
	return(this->error);
}

Toy & Toy::operator =(Toy const & toy)
{
	this->type = toy.type;
	this->name = toy.name;
	this->picture = toy.picture;
	return(*this);
}

Toy & Toy::operator<<(std::string const & ascii)
{
	this->picture.data = ascii;
	return(*this);
}

Toy::Error::Error() : type(UNKNOWN)
{
}

void Toy::Error::setType(ErrorType type)
{
	this->type = type;
}

std::string Toy::Error::what() const
{
    const char *illustration = "bad new illustration";
    const char *wrong = "wrong mode";

    switch(type) {
        case PICTURE:
		    return(illustration);
        case SPEAK:
		    return(wrong);
        default:
            return("");
    }
}

std::string Toy::Error::where() const
{
    const char *ascii = "setAscii";
    const char *speak = "speak_es";

    switch(type) {
        case PICTURE:
            return(ascii);
        case SPEAK:
            return(speak);
        default:
            return("");
    }
}

std::ostream & operator<<(std::ostream & os, Toy const & toy)
{
	return(os << toy.getName() << std::endl << toy.getAscii() << std::endl);
}