/*
** EPITECH PROJECT, 2019
** Woody.hpp
** File description:
** @epitech.eu
*/

#ifndef WOODY_HPP_
	#define WOODY_HPP_

    #include "Toy.hpp"

    class Woody : public Toy {
        public:
            Woody(std::string const & name, std::string const & filename = "woody.txt");
            Woody(Woody const &);
            virtual ~Woody();

            virtual bool speak(std::string const);
    };

#endif /* !WOODY_HPP_ */