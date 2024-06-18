/*
** EPITECH PROJECT, 2019
** EventManager.hpp
** File description:
** @epitech.eu
*/

#ifndef EVENTMANAGER_HPP_
	#define EVENTMANAGER_HPP_

    #include <list>
    #include <iostream>
    #include <string>
    #include "Event.hpp"

    class EventManager {
        public:
            EventManager();
            ~EventManager();
            EventManager(EventManager const &);
            EventManager &operator=(EventManager const&);
            void addEvent(const Event&);
            void removeEventsAt(unsigned int);
            void dumpEvents(void) const;
            void dumpEventAt(unsigned int) const;
            void addTime(unsigned int);
            void addEventList(std::list<Event>);
            unsigned int getTime() const;
            std::list<Event> getEvent() const;
            static bool listSort(Event const& e1, Event const& e2);
        private:
            unsigned int _time;
            std::list<Event> _event;
    };

#endif /* !EVENTMANAGER_HPP_ */