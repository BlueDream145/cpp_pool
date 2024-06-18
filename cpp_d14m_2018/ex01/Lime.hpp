/*
** EPITECH PROJECT, 2019
** Lime.hpp
** File description:
** @epitech.eu
*/

#ifndef LIME_HPP_
	#define LIME_HPP_

    #include "Lemon.hpp"

    class Lime : public Lemon {
        public:
            Lime();
            ~Lime();
            int getVitamins() const;
            std::string getName() const;
    };

#endif /* !LIME_HPP_ */