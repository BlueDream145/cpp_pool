/*
** EPITECH PROJECT, 2019
** Parts.cpp
** File description:
** @epitech.eu
*/

#include "Parts.hpp"

static const char *ok = "OK";
static const char *ko = "KO";
static const char *status = " status : ";

// Arms

Arms::Arms(std::string serial, bool functionnal)
{
    this->_serial = serial;
    this->_functionnal = functionnal;
}

const std::string Arms::serial()
{
    return(this->_serial);
}

const bool Arms::getFunctionnal()
{
    return(this->_functionnal);
}

const void Arms::informations()
{
    std::cout << "\t[Parts] Arms " << this->_serial << status << (this->_functionnal ? ok : ko) << std::endl;
}

// Legs

Legs::Legs(std::string serial, bool functionnal)
{
    this->_serial = serial;
    this->_functionnal = functionnal;
}

const std::string Legs::serial()
{
    return(this->_serial);
}

const bool Legs::getFunctionnal()
{
    return(this->_functionnal);
}

const void Legs::informations()
{
    std::cout << "\t[Parts] Legs " << this->_serial << status << (this->_functionnal ? ok : ko) << std::endl;
}

// Head

Head::Head(std::string serial, bool functionnal)
{
    this->_serial = serial;
    this->_functionnal = functionnal;
}

const std::string Head::serial()
{
    return(this->_serial);
}

const bool Head::getFunctionnal()
{
    return(this->_functionnal);
}

const void Head::informations()
{
    std::cout << "\t[Parts] Head " << this->_serial << status << (this->_functionnal ? ok : ko) << std::endl;
}