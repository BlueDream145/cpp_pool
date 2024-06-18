/*
** EPITECH PROJECT, 2019
** Event.hpp
** File description:
** @epitech.eu
*/

#ifndef EVENT_HPP_
	#define EVENT_HPP_

    #include <string>

    class Event {
        public:
            Event(void);
            Event(unsigned int, const std::string&);
            ~Event(void);
            Event& operator=(const Event&);
            unsigned int getTime(void) const;
            const std::string getEvent(void) const;
            void setTime(unsigned int);
            void setEvent(const std::string&);
        private:
            unsigned int _time;
            std::string	_str;
    };

#endif /* !EVENT_HPP_ */