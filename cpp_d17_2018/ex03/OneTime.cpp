/*
** EPITECH PROJECT, 2019
** OneTime.cpp
** File description:
** @epitech.eu
*/

#include <iostream>

#include "OneTime.hpp"

OneTime::OneTime(std::string key)
{
	this->key = key;
	index = 0;
}

OneTime::~OneTime()
{
}

void OneTime::encryptChar(char plainChar)
{
	if (isalpha(plainChar)) {
        int bas;
        int k;

        if (plainChar > 96)
            bas = 97;
        else
            bas = 65;
        if (key[index] > 96)
            k = 97;
        else
            k = 65;
        plainChar -= bas + (key[index] - k);
        plainChar %= 26;
        plainChar += bas;
    }
	std::cout << plainChar;
	index = ((index + 1) % key.size());
}

void OneTime::decryptChar(char cipherChar)
{
	if (isalpha(cipherChar)) {
        int bas;
        int k;
        
        if (cipherChar > 96)
            bas = 122;
        else
            bas = 90;
        if (key[index] > 96)
            k = 97;
        else
            k = 65;
        cipherChar -= bas - (key[index] - k);
        cipherChar %= 26;
        cipherChar += bas;
    }
	std::cout << cipherChar;
	index = ((index + 1) % key.size());
}

void OneTime::reset()
{
	index = 0;
}