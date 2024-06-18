/*
** EPITECH PROJECT, 2019
** Cesar.cpp
** File description:
** @epitech.eu
*/

#include <iostream>

#include "Cesar.hpp"

Cesar::Cesar()
{
	reset();
}

Cesar::~Cesar()
{
}

void Cesar::encryptChar(char plainChar)
{
	if (isalpha(plainChar)) {
        int val;

        if (plainChar > 96)
            val = 97;
        else
            val = 65;
        plainChar = (plainChar - val + this->decal);
        plainChar %= 26;
        plainChar += val;
    }
	decal++;
    decal %= 26;
	std::cout << plainChar;
}

void Cesar::decryptChar(char cipherChar)
{
	if (isalpha(cipherChar)) {
        int val;
        
        if (cipherChar > 96)
            val = 122;
        else
            val = 90;
        cipherChar = (cipherChar - val - decal);
        cipherChar %= 26;
        cipherChar += val;
    }
	decal++;
    decal %= 26;
	std::cout << cipherChar;
}

void Cesar::reset()
{
	decal = 3;
}
