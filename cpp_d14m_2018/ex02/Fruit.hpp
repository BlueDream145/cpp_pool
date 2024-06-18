/*
** EPITECH PROJECT, 2019
** Fruit.hpp
** File description:
** @epitech.eu
*/

#ifndef FRUIT_HPP_
	#define FRUIT_HPP_

    #include <string>
    #include <iostream>

    class Fruit {
        public:
            Fruit();
            Fruit(std::string const &, int);
            virtual ~Fruit();

            virtual std::string const & getName() const = 0;
            int getVitamins() const;

        protected:
            int _vitamins;
            std::string name;
    };

#endif /* !FRUIT_HPP_ */