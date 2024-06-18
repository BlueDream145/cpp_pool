/*
** EPITECH PROJECT, 2019
** Toy.hpp
** File description:
** @epitech.eu
*/

#ifndef TOY_HPP_
	#define TOY_HPP_

    #include "Object.hpp"

    class Toy : public Object
    {
        public:
            Toy(std::string const &);
            virtual	~Toy();
            virtual void isTaken() = 0;
    };

#endif /* !TOY_HPP_ */
