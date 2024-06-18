/*
** EPITECH PROJECT, 2019
** LittlePony.hpp
** File description:
** @epitech.eu
*/

#ifndef LITTLEPONY_HPP_
	#define LITTLEPONY_HPP_

    #include <string>

    #include "Toy.hpp"

    class LittlePony : public Toy
    {
        public:
            LittlePony(std::string const &);
            ~LittlePony();
            void isTaken();
    };

#endif /* !LITTLEPONY_HPP_ */