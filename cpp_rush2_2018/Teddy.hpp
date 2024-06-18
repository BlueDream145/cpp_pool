/*
** EPITECH PROJECT, 2019
** Teddy.hpp
** File description:
** @epitech.eu
*/

#ifndef TEDDY_HPP_
	#define TEDDY_HPP_

    #include <string>

    #include "Toy.hpp";

    class Teddy : public Toy
    {
        public:
            Teddy(std::string const &);
            ~Teddy();
            void	isTaken();
    };

#endif /* !TEDDY_HPP_ */
