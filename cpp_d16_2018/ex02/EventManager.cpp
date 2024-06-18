/*
** EPITECH PROJECT, 2019
** EventManager.cpp
** File description:
** @epitech.eu
*/

#include "EventManager.hpp"

EventManager::EventManager() : _time(0)
{
}

EventManager::~EventManager()
{
}

unsigned int EventManager::getTime() const
{
    return(_time);
}

std::list<Event> EventManager::getEvent() const
{
    return(_event);
}

EventManager::EventManager(EventManager const &ev)
{
    _event = ev.getEvent();
    _time = ev.getTime();
}

EventManager &EventManager::operator=(EventManager const &ev)
{
    _event = ev.getEvent();
    _time = ev.getTime();
    return(*this);
}

bool sortTime(const Event &a, const Event &b)
{
    if (a.getTime() <= b.getTime())
        return(true);
    return(false);
}

void EventManager::addEvent(const Event &ev)
{
    _event.push_back(ev);
    _event.sort(sortTime);
}

void EventManager::removeEventsAt(unsigned int time)
{
    for (std::list<Event>::iterator it = _event.begin(); it != _event.end(); ++it)
        if (it->getTime() == time)
        {
            it = _event.erase(it);
            it--;
        }
}

void EventManager::dumpEvents(void) const
{
    for (std::list<Event>::const_iterator it = _event.begin(); it != _event.end(); ++it)
        if (it->getTime() > _time)
            std::cout << it->getTime() << ": " << it->getEvent() << std::endl;
}

void EventManager::dumpEventAt(unsigned int time) const
{
    for (std::list<Event>::const_iterator it = _event.begin(); it != _event.end(); ++it)
        if (it->getTime() == time)
            std::cout << it->getTime() << ": " << it->getEvent() << std::endl;
}

void EventManager::addTime(unsigned int time)
{
    for (Event x : _event) {
		if (x.getTime() > _time
		    && x.getTime() <= _time + time) {
			std::cout << x.getEvent() << std::endl;
		}
	}
	unsigned int r = _time;
	_event.remove_if
		([r](const Event &event) {
		    return r > event.getTime();
		});
    _time += time;
}

void EventManager::addEventList(std::list<Event> ev)
{
    for (std::list<Event>::iterator itr = ev.begin(); itr != ev.end(); ++itr)
        if ((*itr).getTime() > _time)
            _event.push_back(*itr);
    _event.sort(EventManager::listSort);
}

bool EventManager::listSort(Event const& e1, Event const& e2)
{
    if (e1.getTime() > e2.getTime())
        return false;
    return true;
}