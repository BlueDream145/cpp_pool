/*
** EPITECH PROJECT, 2019
** PlasmaRifle.cpp
** File description:
** @epitech.eu
*/

#ifndef PLASMARIFLE_HPP_
    #define PLASMARIFLE_HPP_

    #include <string>
    #include <iostream>

    #include "AWeapon.hpp"

    class PlasmaRifle : public AWeapon {
        public:
            PlasmaRifle();
            virtual ~PlasmaRifle();
            virtual void attack() const;
    };

#endif /* !PLASMARIFLE_HPP_ */