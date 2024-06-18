/*
** EPITECH PROJECT, 2019
** ToyStory.hpp
** File description:
** @epitech.eu
*/

#ifndef TOYSTORY_HPP_
	#define TOYSTORY_HPP_

    #include <string>

    #include "Toy.hpp"

    typedef bool (Toy::*toy_speak)(std::string const message);

    class ToyStory {
        public:
            ToyStory();
            ~ToyStory();

	        static bool tellMeAStory(std::string const &, Toy &, toy_speak, Toy &, toy_speak);
    };

#endif /* !TOYSTORY_HPP_ */