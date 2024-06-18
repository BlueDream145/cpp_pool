/*
** EPITECH PROJECT, 2019
** KreogCom.cpp
** File description:
** @epitech.eu
*/

#include "KreogCom.hpp"

static const char *kreogcom = "KreogCom ";

KreogCom::KreogCom(int x, int y, int serial)
{
    const char *init = " initialised";

    this->_x = x;
    this->_y = y;
    this->m_serial = serial;
    this->_next = 0;
    std::cout << kreogcom << this->m_serial << init << std::endl;
}

KreogCom::~KreogCom()
{
    const char *shutdown = " shutting down";

    std::cout << kreogcom << this->m_serial << shutdown << std::endl;
}

void KreogCom::addCom(int x, int y, int serial)
{
    KreogCom *com = new KreogCom(x, y, serial);

    com->_next = this->_next;
    this->_next = com;
}

KreogCom *KreogCom::getCom()
{
    return(_next);
}

void KreogCom::removeCom()
{
    KreogCom *del;

    if (!this->_next)
        return;
    del = this->_next;
    this->_next = this->_next->_next;
    delete del;
}

const void KreogCom::ping()
{
    const char *currently = " currently at ";

    std::cout << kreogcom << this->m_serial << currently << this->_x << " " << this->_y << std::endl;
}

const void KreogCom::locateSquad()
{
    if (this->_next)
        this->_next->locateSquad();
    this->ping();
}