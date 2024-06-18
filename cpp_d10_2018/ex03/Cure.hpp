/*
** EPITECH PROJECT, 2019
** Cure.hpp
** File description:
** @epitech.eu
*/

#ifndef CURE_HPP_
    #define CURE_HPP_

    #include "AMateria.hpp"
    #include "ICharacter.hpp"

    class Cure : public AMateria {
        public:
            Cure();
            Cure(Cure const &);
            ~Cure();

            virtual AMateria *clone() const;
            virtual void effect(ICharacter &);
    };

#endif /* !CURE_HPP_ */