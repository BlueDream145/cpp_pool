/*
** EPITECH PROJECT, 2019
** Event.cpp
** File description:
** @epitech.eu
*/

#include "Event.hpp"

Event::Event() : _time(0)
{
}

Event::Event(unsigned int time, const std::string &str) : _time(time), _str(str)
{
}

Event::~Event()
{
}

Event &Event::operator=(const Event& ev)
{
    _time = ev._time;
    _str = ev._str;
    return(*this);
}

unsigned int Event::getTime(void) const
{
    return(_time);
}

const std::string Event::getEvent(void) const
{
    return(_str);
}

void Event::setTime(unsigned int time_)
{
    _time = time_;
}

void Event::setEvent(const std::string & str)
{
    _str = str;
}
