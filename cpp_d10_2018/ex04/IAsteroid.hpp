/*
** EPITECH PROJECT, 2019
** IAsteroid.hpp
** File description:
** @epitech.eu
*/

#ifndef IASTEROID_HPP_
    #define IASTEROID_HPP_

    #include <string>

    class IAsteroid;

    #include "IMiningLaser.hpp"

    class IAsteroid {
        public:
            virtual ~IAsteroid() {}

            virtual std::string beMined(IMiningLaser *) const = 0;
            virtual std::string getName() const = 0;
    };

#endif /* !IASTEROID_HPP_ */