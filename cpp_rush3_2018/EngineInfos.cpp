/*
** EPITECH PROJECT, 2019
** EngineInfos.cpp
** File description:
** EngineInfos
*/

#include "EngineInfos.hpp"

EngineInfos::EngineInfos()
{
}

EngineInfos::~EngineInfos()
{

}

EngineInfos& EngineInfos::operator=(EngineInfos const &other)
{
    this->_core = other._core;
    this->_user = other._user;
    return(*this);
}