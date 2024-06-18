/*
** EPITECH PROJECT, 2019
** ISpaceMarine.hpp
** File description:
** @epitech.eu
*/

#ifndef ISPACEMARINE_HPP_
    #define ISPACEMARINE_HPP_

    class ISpaceMarine {
        public:
            virtual ISpaceMarine *clone() const = 0;
            virtual ~ISpaceMarine() {}
            virtual void battleCry() const = 0;
            virtual void rangedAttack() const = 0;
            virtual void meleeAttack() const = 0;
    };

#endif /* !ISPACEMARINE_HPP_ */