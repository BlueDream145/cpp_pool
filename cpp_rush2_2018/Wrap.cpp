/*
** EPITECH PROJECT, 2019
** Wrap.cpp
** File description:
** @epitech.eu
*/

#include <string>
#include <iostream>

#include "Wrap.hpp"

Wrap::Wrap(const std::string &tit) : Object(tit)
{
	this->_obj = NULL;
	this->isOpen = false;
}

Wrap::~Wrap()
{

}

bool Wrap::wrapMeThat(Object *obj)
{
    const char *tuut = "tuuuut tuuut tuut";
    const char *sobj = "The object to wrap doesn't exist, or there is already an object in the wrap.";

	if (this->_obj == NULL || obj == NULL)
	{
		this->_obj = obj;
		std::cout << tuut << std::endl;
		this->isOpen = false;
		return(true);
	}
	else
		std::cout << sobj << std::endl;
	return(false);
}

void Wrap::openMe()
{
	this->isOpen = true;
}

Object *Wrap::getObj()
{
    const char *closed = "Wrap is closed and the object can't be get.";
	if (this->isOpen == true)
		return(this->_obj);
	else
		std::cout << closed << std::endl;
		return(NULL);
}