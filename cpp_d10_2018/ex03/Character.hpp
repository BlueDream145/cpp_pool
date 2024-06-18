/*
** EPITECH PROJECT, 2019
** Character.hpp
** File description:
** @epitech.eu
*/

#ifndef CHARACTER_HPP_
    #define CHARACTER_HPP_

    #include <string>

    #include "ICharacter.hpp"
    #include "AMateria.hpp"

    class Character : public ICharacter {
        public:
            Character(std::string const &);
            Character(Character const &);
            ~Character();

            virtual std::string const & getName() const;
            virtual void equip(AMateria *);
            virtual void unequip(int);
            virtual void use(int, ICharacter &);
        protected:
            AMateria *slots[4];
            std::string name;
    };

#endif /* !CHARACTER_HPP_ */