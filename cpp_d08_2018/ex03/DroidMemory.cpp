/*
** EPITECH PROJECT, 2019
** droidmemory.cpp
** File description:
** @epitech.eu
*/

#include "DroidMemory.hpp"

DroidMemory::DroidMemory() : _exp(0) {
    _fingerPrint = random();
}

DroidMemory::~DroidMemory() {

}

size_t DroidMemory::getFingerPrint() const {
    return(_fingerPrint);
}

size_t DroidMemory::getExp() const {
    return(this->_exp);
}

void DroidMemory::setFingerPrint(size_t fingerPrint) {
    this->_fingerPrint = fingerPrint;
}

void DroidMemory::setExp(size_t exp) {
    this->_exp = exp;
}

void DroidMemory::addExp(size_t exp) {
    this->_exp += exp;
}

DroidMemory & DroidMemory::operator <<(DroidMemory const & memory) {
    DroidMemory::fusion(*this, *this, memory);
    return(*this);
}

DroidMemory const & DroidMemory::operator >>(DroidMemory & memory) const {
    DroidMemory::fusion(memory, *this, memory);
    return(*this);
}

DroidMemory & DroidMemory::operator +=(DroidMemory const & memory) {
    DroidMemory::fusion(*this, *this, memory);
    return(*this);
}

DroidMemory & DroidMemory::operator +=(size_t exp) {
    DroidMemory mem;

    mem._exp = exp;
    mem._fingerPrint = exp;
    DroidMemory::fusion(*this, *this, mem);
    return(*this);
}

DroidMemory & DroidMemory::operator+(DroidMemory const & mem) const {
    DroidMemory *tmp = new DroidMemory();

    DroidMemory::fusion(*tmp, *this, mem);
    return *tmp;
}

DroidMemory & DroidMemory::operator+(size_t exp) const {
    DroidMemory mem;

    mem._exp = exp;
    mem._fingerPrint = exp;
    DroidMemory *tmp = new DroidMemory();
    DroidMemory::fusion(*tmp, *this, mem);
    return(*tmp);
}

bool DroidMemory::operator ==(DroidMemory const & memory) const {
    return(this->_exp == memory._exp &&
        this->_fingerPrint == memory._fingerPrint);
}

bool DroidMemory::operator !=(DroidMemory const & memory) const {
    return(!(*this == memory));
}

bool DroidMemory::operator <(DroidMemory const & memory) const {
    return(this->_exp < memory._exp);
}

bool DroidMemory::operator <=(DroidMemory const & memory) const {
    return(this->_exp <= memory._exp);
}

bool DroidMemory::operator >(DroidMemory const & memory) const {
    return(this->_exp > memory._exp);
}

bool DroidMemory::operator >=(DroidMemory const & memory) const {
    return(this->_exp >= memory._exp);
}

bool DroidMemory::operator <(size_t memory) const {
    return(this->_exp < memory);
}

bool DroidMemory::operator <=(size_t memory) const {
    return(this->_exp <= memory);
}

bool DroidMemory::operator >(size_t memory) const {
    return(this->_exp > memory);
}

bool DroidMemory::operator >=(size_t memory) const {
    return(this->_exp >= memory);
}

void DroidMemory::fusion(DroidMemory &dest, DroidMemory const &memory1, DroidMemory const &memory2) {
    dest._exp = memory1._exp + memory2._exp;
    dest._fingerPrint = memory1._fingerPrint ^ memory2._fingerPrint;
}

std::ostream & operator<<(std::ostream & os, DroidMemory const & memory) {
    const char *droid = "Droid Memory '";
    const char *separator = "', ";

    return os << droid << memory.getFingerPrint() << separator << memory.getExp();
}
