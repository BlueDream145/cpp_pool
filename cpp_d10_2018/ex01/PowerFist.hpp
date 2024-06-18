/*
** EPITECH PROJECT, 2019
** PowerFist.hpp
** File description:
** @epitech.eu
*/

#ifndef POWERFIST_HPP_
    #define POWERFIST_HPP_

    #include "AWeapon.hpp"

    class PowerFist : public AWeapon {
        public:
            PowerFist();
            virtual ~PowerFist();
            virtual void attack() const;
    };

#endif /* !POWERFIST_HPP_ */