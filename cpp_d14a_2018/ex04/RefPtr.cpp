/*
** EPITECH PROJECT, 2019
** RefPtr.cpp
** File description:
** RefPtr
*/

#include "RefPtr.hpp"

RefPtr::RefPtr(BaseComponent *rawPtr) : _rawPtr(rawPtr), _refCounter(new int)
{
	*_refCounter = 1;
}

RefPtr::RefPtr(RefPtr const &other) : _rawPtr(other._rawPtr), _refCounter(other._refCounter)
{
	(*_refCounter)++;
}

RefPtr::~RefPtr()
{
	if (--(*_refCounter) == 0)
		delete _rawPtr;
}

RefPtr &RefPtr::operator=(RefPtr const &obj)
{
	if (--(*_refCounter) == 0)
		delete _rawPtr;
	_rawPtr = obj._rawPtr;
	_refCounter = obj._refCounter;
	(*_refCounter)++;
	return (*this);
}

BaseComponent *RefPtr::get() const
{
	return _rawPtr;
}