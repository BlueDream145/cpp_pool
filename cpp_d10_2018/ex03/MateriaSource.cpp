/*
** EPITECH PROJECT, 2019
** MateriaSource.cpp
** File description:
** @epitech.eu
*/

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for(int i = 0; i < 4; i++)
        slots[i] = NULL;
}

MateriaSource::~MateriaSource()
{
    for(int i = 0; i < 4; i++)
        if (slots[i])
            delete slots[i];
}

void MateriaSource::learnMateria(AMateria* materia)
{
    if (!materia)
        return;
    for (int i = 0; i < 4; i++)
        if (!slots[i]) {
            slots[i] = materia;
            return;
        }
}

AMateria *MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
        if (slots[i] && slots[i]->getType() == type)
            return slots[i]->clone();
    return(NULL);
}
