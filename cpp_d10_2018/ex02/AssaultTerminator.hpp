/*
** EPITECH PROJECT, 2019
** AssaultTerminator.hpp
** File description:
** @epitech.eu
*/

#ifndef ASSAULTTERMINATOR_HPP_
    #define ASSAULTTERMINATOR_HPP_

    #include <string>

    #include "ISpaceMarine.hpp"

    class AssaultTerminator : public ISpaceMarine {
        public:
            AssaultTerminator();
            AssaultTerminator(AssaultTerminator const & marine);
            virtual ~AssaultTerminator();

            virtual ISpaceMarine *clone() const;
            virtual void battleCry() const;
            virtual void rangedAttack() const;
            virtual void meleeAttack() const; 
        protected:
            void speak(std::string) const;
        private:
    };

#endif /* !ASSAULTTERMINATOR_HPP_ */