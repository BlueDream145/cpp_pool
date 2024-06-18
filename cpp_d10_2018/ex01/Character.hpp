/*
** EPITECH PROJECT, 2019
** Character.hpp
** File description:
** @epitech.eu
*/

#ifndef CHARACTER_HPP_
    #define CHARACTER_HPP_

    #include <iostream>

    #include "AEnemy.hpp"
    #include "AWeapon.hpp"

    class Character {
        public:
            Character(std::string);
            ~Character();

            void recoverAP();
            void equip(AWeapon *);
            void attack(AEnemy *);
            bool action(int);
            std::string const & getName() const;
            int getAp() const;
            AWeapon *getWeapon() const;
        protected:
            std::string name;
            int ap;
            AWeapon *weapon;
    };
    
    std::ostream & operator<<(std::ostream & os, Character const & perso);

#endif /* !CHARACTER_HPP_ */