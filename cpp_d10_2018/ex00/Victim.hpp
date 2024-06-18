/*
** EPITECH PROJECT, 2019
** Victim.hpp
** File description:
** @epitech.eu
*/

#ifndef VICTIM_HPP_
    #define VICTIM_HPP_

    #include <string>

    class Victim {
        public:
            Victim(std::string name);
            virtual ~Victim();

            virtual std::string getName() const;
            virtual void getPolymorphed() const;
        protected:
            std::string name;
    };

    std::ostream & operator<<(std::ostream & os, Victim & victim);

#endif /* !VICTIM_HPP_ */