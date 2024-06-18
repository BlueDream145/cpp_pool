/*
** EPITECH PROJECT, 2019
** Banana.hpp
** File description:
** @epitech.eu
*/

#ifndef BANANA_HPP_
	#define BANANA_HPP_

    #include <string>

    #include "Fruit.hpp"

    class Banana : public Fruit {
        public:
            Banana();
            ~Banana();
            int getVitamins() const;
            virtual std::string const & getName() const;
    };

#endif /* !BANANA_HPP_ */