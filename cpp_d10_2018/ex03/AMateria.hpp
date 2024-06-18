/*
** EPITECH PROJECT, 2019
** AMetaria.hpp
** File description:
** @epitech.eu
*/

#ifndef AMATERIA_HPP_
    #define AMATERIA_HPP_

    #include <string>
    #include <iostream>

    class AMateria;

    #include "ICharacter.hpp"

    class AMateria {
        public:
            AMateria(std::string const &);
            ~AMateria();
            std::string const & getType() const;
            unsigned int getXP() const;
            virtual AMateria *clone() const = 0;
            virtual void use(ICharacter &);
            virtual void effect(ICharacter &);
        protected:
            unsigned int xp;
            std::string type;
            void speak(std::string);
        private:
    };

#endif /* !AMATERIA_HPP_ */