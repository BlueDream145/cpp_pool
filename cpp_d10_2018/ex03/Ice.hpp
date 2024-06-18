/*
** EPITECH PROJECT, 2019
** Ice.hpp
** File description:
** @epitech.eu
*/

#ifndef ICE_HPP_
    #define ICE_HPP_

    #include "AMateria.hpp"
    #include "ICharacter.hpp"

    class Ice : public AMateria {
        public:
            Ice();
            Ice(Ice const & ice);
            ~Ice();

            virtual AMateria * clone() const;
            virtual void effect(ICharacter &);
    };

#endif /* !ICE_HPP_ */