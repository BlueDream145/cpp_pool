/*
** EPITECH PROJECT, 2019
** Squad.cpp
** File description:
** @epitech.eu
*/

#include <iostream>

#include "Squad.hpp"

Squad::Squad() : count(0), size(10)
{
    this->array = new ISpaceMarine*[size];

    for (int i = 0; i < size;)
        this->array[i++] = NULL;
}

Squad::Squad(Squad const & squad)
{
    this->count = squad.count;
    this->size = squad.size;
    this->array = new ISpaceMarine*[size];

    for (int i = 0; i < size; i++) {
        array[i] = NULL;
        if (squad.array[i])
            array[i] = squad.array[i]->clone();
    }
}

Squad::~Squad()
{
    for (int i = 0; i < (int)this->count; i++)
        delete(array[i]);
    delete[] array;
}

int Squad::getCount() const
{
    return(this->count);
}

ISpaceMarine *Squad::getUnit(int position)
{
    if (position > size || position < 0)
        return(NULL);
    return(array[position]);
}

int Squad::push(ISpaceMarine *marine)
{
    if (!marine)
        return(this->count);

    if (count >= size)
        resize();
    for (int i = 0; i < count;)
        if (array[i++] == marine)
            return(count);
    array[count++] = marine;
    return(count);
}

Squad & Squad::operator =(Squad const & squad)
{
    for (int i = 0; i < count;)
        delete array[i];
    delete[] array;
    this->count = squad.count;
    this->size = squad.size;
    array = new ISpaceMarine*[this->size];
    for (int i = 0; i < size; i++) {
        array[i] = NULL;
        if (squad.array[i])
            array[i] = squad.array[i]->clone();
    }
    return(*this);
}

void Squad::resize()
{
    size_t new_size = size * 1.5;
    ISpaceMarine **new_array = new ISpaceMarine *[new_size];
    int i = 0;

    for (i = 0; i < (int) size; i++)
        new_array[i] = array[i];
    while (i < (int) new_size)
        new_array[i++] = NULL;
    delete[] array;
    array = new_array;
    this->size = new_size;
}
