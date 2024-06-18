/*
** EPITECH PROJECT, 2019
** Box.cpp
** File description:
** @epitech.eu
*/

#include <iostream>

#include "Box.hpp"

static const char *box = "Box";

Box::Box() : Wrap(box)
{
}

void Box::closeMe()
{
	if (this->isOpen == false)
		std::cout << "Box already opened." << std::endl;
	this->isOpen = false;
}

bool Box::wrapMeThat(Object *obj)
{
	if (this->isOpen == true)
		return (Wrap::wrapMeThat(obj));
	else
		std::cout << "Box is closed and can't be used to wrap anything." << std::endl;
	return (false);
}