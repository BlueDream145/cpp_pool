/*
** EPITECH PROJECT, 2019
** TacticalMarine.hpp
** File description:
** @epitech.eu
*/

#ifndef TACTICALMARINE_HPP_
    #define TACTICALMARINE_HPP_

    #include <string>

    #include "ISpaceMarine.hpp"

    class TacticalMarine :public ISpaceMarine {
        public:
            TacticalMarine();
            TacticalMarine(TacticalMarine const &);
            virtual ~TacticalMarine();

            virtual ISpaceMarine *clone() const;
            virtual void battleCry() const;
            virtual void rangedAttack() const;
            virtual void meleeAttack() const;
        protected:
            void speak(std::string message) const;
    };

#endif /* !TACTICALMARINE_HPP_ */