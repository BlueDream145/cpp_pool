/*
** EPITECH PROJECT, 2019
** MateriaSource.hpp
** File description:
** @epitech.eu
*/

#ifndef MATERIASOURCE_HPP_
    #define MATERIASOURCE_HPP_

    #include "AMateria.hpp"
    #include "IMateriaSource.hpp"

    class MateriaSource : public IMateriaSource {
        public:
            MateriaSource();
            ~MateriaSource();

            virtual void learnMateria(AMateria*);
            virtual AMateria *createMateria(std::string const &);
        protected:
            AMateria *slots[4];
    };

#endif /* !MATERIASOURCE_HPP_ */