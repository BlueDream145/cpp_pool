/*
** EPITECH PROJECT, 2019
** Picture.cpp
** File description:
** @epitech.eu
*/

#include <string>
#include <fstream>
#include <sstream>

#include "Picture.hpp"

Picture::Picture() : data("")
{
}

Picture::Picture(const std::string & name)
{
    getPictureFromFile(name);
}

Picture::~Picture()
{
}

bool Picture::getPictureFromFile(const std::string & name)
{
    const char *error = "ERROR";
    std::ifstream stream(name.data());

    if (!stream.is_open()) {
        this->data = error;
        return(false);
    }
    std::stringstream buff;
    buff << stream.rdbuf();
    this->data = buff.str();
    return(true);
}

Picture	&Picture::operator=(Picture const & content)
{
    this->data = content.data;
    return(*this);
}