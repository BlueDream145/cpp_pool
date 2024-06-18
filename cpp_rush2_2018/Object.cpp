/*
** EPITECH PROJECT, 2019
** Object.cpp
** File description:
** @epitech.eu
*/

#include "Object.hpp"

Object::Object(const std::string &tit) : title(tit)
{

}

Object::~Object()
{
}

const std::string &Object::getTitle() const
{
	return(this->title);
}