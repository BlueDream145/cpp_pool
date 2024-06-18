/*
** EPITECH PROJECT, 2019
** Peon.hpp
** File description:
** Peon.hpp
*/

#ifndef PEON_HPP_
    #define PEON_HPP_

    #include <string>

    #include "Victim.hpp"

    class Peon : public Victim {
        public:
            Peon(std::string);
            virtual ~Peon();
            void getPolymorphed() const;
    };

#endif /* !PEON_HPP_ */