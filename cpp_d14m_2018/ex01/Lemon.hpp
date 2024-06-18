/*
** EPITECH PROJECT, 2019
** Lemon.hpp
** File description:
** @epitech.eu
*/

#ifndef LEMON_HPP_
	#define LEMON_HPP_

    #include "Fruit.hpp"

    class Lemon : public Fruit {
        public:
            Lemon();
            Lemon(std::string const & name_, int vitamins_);
            ~Lemon();
            virtual std::string const & getName() const;
    };

#endif /* !LEMON_HPP_ */