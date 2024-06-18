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
            virtual ~Fruit();

            std::string const & getName() const;
            int getVitamins() const;

        protected:
            int _vitamins;
            std::string name;
            
            Fruit();
            Fruit(std::string const &, int);
    };

#endif /* !FRUIT_HPP_ */