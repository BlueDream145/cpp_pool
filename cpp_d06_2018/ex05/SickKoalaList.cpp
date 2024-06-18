/*
** EPITECH PROJECT, 2019
** SIckKoalaList.cpp
** File description:
** @epitech.eu
*/

#include <iostream>
#include <cstring>
#include "SickKoalaList.hpp"

SickKoalaList::SickKoalaList(SickKoala *koala)
{
    this->content = koala;
    this->next = NULL;
    this->name = "NULL";
}

SickKoalaList::~SickKoalaList()
{
}

bool SickKoalaList::isEnd()
{
    if (this->getNext() == NULL)
        return(true);
    return(false);
}

void SickKoalaList::append(SickKoalaList *list)
{
    if (this->isEnd())
        this->setNext(list);
    else
        this->next->append(list);
}

SickKoalaList *SickKoalaList::remove(SickKoalaList *list)
{
    if (!list)
        return(this);
    if (list == this)
        return(this->next);
    if (this->next)
    {
        if (this->next == list)
            this->next = this->next->getNext();
        else
            this->next->remove(list);
    }
    return(this);
}

SickKoalaList *SickKoalaList::removeFromName(std::string koalaName)
{
    SickKoalaList *current = this;
    SickKoalaList *before = NULL;

    while(current != NULL) {
        if (current->content
            && current->content->getName() == koalaName) {
            if (before) {
                before->setNext(current->getNext());
                current->setNext(NULL);
                break;
            } else {
                before = current->getNext();
                current->setNext(NULL);
            }
            before = current;
            current = current->next;
        }
    }
    return(this);
}

SickKoala *SickKoalaList::getContent()
{
    return(this->content);
}

std::string SickKoalaList::getName()
{
    return(this->name);
}

void SickKoalaList::setNext(SickKoalaList *list)
{
    this->next = list;
}

SickKoalaList *SickKoalaList::getNext()
{
    return(this->next);
}

void SickKoalaList::dump()
{
    const char *patients = "Patients: ";
    const char *separator = ", ";
    
    std::cout << patients;
    for (SickKoalaList *obj = this; obj; obj = obj->getNext())
        std::cout << (obj == this ? "" : separator)
        << (obj->getContent() ? obj->getContent()->getName() : "[NULL]");
    std::cout << "." << std::endl;
}