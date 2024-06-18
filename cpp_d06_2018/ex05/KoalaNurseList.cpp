/*
** EPITECH PROJECT, 2019
** KoalaNurseList.c
** File description:
** @epitech.eu
*/

#include "KoalaNurseList.hpp"

KoalaNurseList::KoalaNurseList(KoalaNurse *koala)
{
    this->content = koala;
    this->next = NULL;
}

KoalaNurseList::~KoalaNurseList()
{
}

bool KoalaNurseList::isEnd()
{
    if (this->getNext() == NULL)
        return(true);
    return(false);
}

KoalaNurseList *KoalaNurseList::getNext()
{
    return(this->next);
}

KoalaNurse *KoalaNurseList::getContent()
{
    return(this->content);
}

KoalaNurse *KoalaNurseList::getFromID(int id)
{
    KoalaNurseList *current = this;

    while(current != NULL)
        if (current->content
            && current->content->getID() == id)
            return(current->getContent());
    return(NULL);
}

void KoalaNurseList::setNext(KoalaNurseList *list)
{
    this->next = list;
}

void KoalaNurseList::append(KoalaNurseList *list)
{
    if (this->isEnd())
        this->setNext(list);
    else
        this->next->append(list);
}

void KoalaNurseList::dump()
{
    const char *patients = "Nurses: ";
    const char *separator = ", ";
    
    std::cout << patients;
    for (KoalaNurseList *obj = this; obj; obj = obj->getNext())
        std::cout << (obj == this ? "" : separator)
        << (obj->getContent() ?
        std::to_string(obj->getContent()->getID()) : "[NULL]");
    std::cout << "." << std::endl;
}

KoalaNurseList *KoalaNurseList::remove(KoalaNurseList *list)
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

KoalaNurseList *KoalaNurseList::removeFromID(int koalaId)
{
    KoalaNurseList *current = this;
    KoalaNurseList *before = NULL;

    while(current != NULL) {
        if (current->content
            && current->content->getID() == koalaId) {
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