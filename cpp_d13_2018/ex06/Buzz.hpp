/*
** EPITECH PROJECT, 2019
** Buzz.hpp
** File description:
** @epitech.eu
*/

#ifndef BUZZ_HPP_
	#define BUZZ_HPP_

    #include "Toy.hpp"

    class Buzz : public Toy {
        public:
            Buzz(std::string const & name, std::string const & filename = "buzz.txt");
            Buzz(Buzz const &);
            ~Buzz();

            virtual bool speak(std::string const);
            virtual bool speak_es(std::string const);
    };

#endif /* !BUZZ_HPP_ */