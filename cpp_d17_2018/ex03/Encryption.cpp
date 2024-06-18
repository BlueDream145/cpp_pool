/*
** EPITECH PROJECT, 2019
** Encryption.cpp
** File description:
** @epitech.eu
*/

#include "Encryption.hpp"

Encryption::Encryption(IEncryptionMethod & instance, IEMethod method)
{
	this->instance = &instance;
	this->method = method;
}

Encryption::~Encryption()
{
}

void Encryption::operator()(char ch)
{
	(instance->*method)(ch);
}

void Encryption::encryptString(IEncryptionMethod& method, std::string const & data)
{
	method.reset();
	std::for_each(data.begin(), data.end(), Encryption(method, &IEncryptionMethod::encryptChar));
	std::cout << std::endl;
}

void Encryption::decryptString(IEncryptionMethod& method, std::string const & data)
{
	method.reset();
	std::for_each(data.begin(), data.end(), Encryption(method, &IEncryptionMethod::decryptChar));
	std::cout << std::endl;
}
