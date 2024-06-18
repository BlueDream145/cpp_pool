/*
** EPITECH PROJECT, 2019
** DomesticKoala.cpp
** File description:
** @epitech.eu
*/

#include "DomesticKoala.hpp"

DomesticKoala::DomesticKoala(KoalaAction& action) : _action(action), _knowAction(256)
{
}

DomesticKoala::~DomesticKoala()
{
}

DomesticKoala::DomesticKoala(DomesticKoala const & other) : _action(other._action), _knowAction(other._knowAction)
{
}

DomesticKoala& DomesticKoala::operator=(DomesticKoala const & other)
{
    _action = other._action;
    _knowAction = other._knowAction;
    return(*this);
}

std::vector<DomesticKoala::methodPointer_t> const* DomesticKoala::getAction() const
{
    return(&_knowAction);
}

void DomesticKoala::learnAction(unsigned char c, methodPointer_t ptr)
{
    _knowAction[c] = ptr;
}

void DomesticKoala::unlearnAction(unsigned char c)
{
    _knowAction[c] = NULL;
}

void DomesticKoala::doAction(unsigned char c, std::string const& str)
{
    methodPointer_t func = _knowAction[c];
    if (func)
        (_action.*func)(str);
}

void DomesticKoala::setKoalaAction(KoalaAction& action)
{
    _action = action;
}