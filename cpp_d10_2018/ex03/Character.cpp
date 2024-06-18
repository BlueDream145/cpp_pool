/*
** EPITECH PROJECT, 2019
** Character.cpp
** File description:
** @epitech.eu
*/

#include "Character.hpp"

Character::Character(std::string const & name) : name(name)
{
    for (int i = 0; i < 4; i++)
        this->slots[i] = NULL;
}

Character::Character(Character const & perso)
{
    this->name = perso.name;
    for (int i = 0; i < 4; i++) {
        if (this->slots[i])
            delete this->slots[i];
        this->slots[i] = NULL;
        if (perso.slots[i])
            this->slots[i] = perso.slots[i]->clone();
    }
}

Character::~Character()
{
}

std::string const & Character::getName() const
{
    return(name);
}

void Character::equip(AMateria* materia)
{
    if (!materia)
        return;
    for(int i = 0; i < 4; i++) {
        if (slots[i] == NULL) {
            slots[i] = materia;
            return;
        }
    }
}

void Character::unequip(int index)
{
    if (index >= 0 && index < 4)
        slots[index] = NULL;
}

void Character::use(int index, ICharacter& target)
{
    if (index >= 0 && index < 4 && slots[index] != NULL)
        slots[index]->use(target);
}
