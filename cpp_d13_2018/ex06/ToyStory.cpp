/*
** EPITECH PROJECT, 2019
** ToyStory.cpp
** File description:
** @epitech.eu
*/

#include <cstring>
#include <iostream>
#include <fstream>

#include "ToyStory.hpp"

ToyStory::ToyStory()
{
}

ToyStory::~ToyStory()
{
}

bool ToyStory::tellMeAStory(std::string const & filename, Toy & character1, toy_speak speak1, Toy & character2, toy_speak speak2)
{
    const char *picture = "picture:";
	std::ifstream file(filename.data());

    if (!file.is_open()) {
		std::cout << "Bad Story" << std::endl;
        return(true);
	}
	
	std::cout << character1.getAscii() << std::endl;
	std::cout << character2.getAscii() << std::endl;

	char buffer[1024];
	std::string sentence;
	size_t index;

	for (int count = 0; !file.eof(); count++)
	{
		memset(buffer, 0, 1024);
		file.getline(buffer, 1024);
		sentence = buffer;
		if (!((index = sentence.find(picture)) == 0)) {
			if (count % 2)
				if (!(character1.*speak1)(sentence))
					return(false);
			else
				if (!(character2.*speak2)(sentence))
					return(false);
        } else {
			std::string picture = sentence.substr(8);
			if (count % 2) {
				if (!character1.setAscii(picture))
					return(false);
				std::cout << character1.getAscii() << std::endl;
			} else {
				if (!character2.setAscii(picture))
					return(false);
				std::cout << character2.getAscii() << std::endl;
			}
		}
	}
    return(true);
}
