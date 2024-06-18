/*
** EPITECH PROJECT, 2019
** WarpSystem.c
** File description:
** @epitech.eu
*/

#include "WarpSystem.hpp"

// #WarpSystem - #QuantumReactor

// Builder / Destructor

WarpSystem::QuantumReactor::QuantumReactor()
{
    this->_stability = true;
}

WarpSystem::QuantumReactor::~QuantumReactor()
{
}

// Get data

bool WarpSystem::QuantumReactor::isStable()
{
    return(this->_stability);
}

// Set data

void WarpSystem::QuantumReactor::setStability(bool val)
{
    this->_stability = val;
}

// #WarpSystem - #Core

WarpSystem::Core::Core(QuantumReactor *reactor)
{
    this->_coreReactor = reactor;
}

WarpSystem::Core::~Core()
{
}

// Data

bool WarpSystem::Core::isStable()
{
    return(this->_coreReactor->isStable());
}

WarpSystem::QuantumReactor *WarpSystem::Core::getQuantumReactor()
{
    return(this->_coreReactor);
}

void WarpSystem::Core::setStability(bool stability)
{
    this->_coreReactor->setStability(stability);
}

// Functions

WarpSystem::QuantumReactor *WarpSystem::Core::checkReactor()
{
    return(this->_coreReactor);
}