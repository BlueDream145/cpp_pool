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
            virtual ~Banana();
            int getVitamins() const;
            std::string getName() const;
    };

#endif /* !BANANA_HPP_ */