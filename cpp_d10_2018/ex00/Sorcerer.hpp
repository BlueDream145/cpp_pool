/*
** EPITECH PROJECT, 2019
** Sorcerer.hpp
** File description:
** @epitech.eu
*/

#ifndef SORCERER_HPP_
    #define SORCERER_HPP_

    #include <string>

    #include "Victim.hpp"

    class Sorcerer {
        public:
            Sorcerer(std::string, std::string);
            virtual ~Sorcerer();

            std::string getName() const;
            std::string getTitle() const;

            virtual void polymorph(Victim const &) const;

        protected:
            std::string name;
            std::string title;
            virtual void speak(std::string);
        private:
    };

    std::ostream & operator<<(std::ostream & os, Sorcerer & sorcerer);

#endif /* !SORCERER_HPP_ */