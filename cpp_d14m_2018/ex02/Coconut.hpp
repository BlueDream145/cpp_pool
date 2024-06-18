/*
** EPITECH PROJECT, 2019
** Coconut.hpp
** File description:
** @epitech.eu
*/

#ifndef COCONUT_HPP_
	#define COCONUT_HPP_

    #include "Fruit.hpp"

    class Coconut : public Fruit {
        public:
            Coconut();
            ~Coconut();
            virtual std::string const & getName() const;
    };

#endif /* !COCONUT_HPP_ */