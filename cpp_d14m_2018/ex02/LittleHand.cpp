/*
** EPITECH PROJECT, 2019
** LittleHand.cpp
** File description:
** @epitech.eu
*/

#include <cstring>
#include "Banana.hpp"
#include "Lemon.hpp"
#include "LittleHand.hpp"
#include "Lime.hpp"

LittleHand::LittleHand()
{
}

LittleHand::~LittleHand()
{
}

void LittleHand::sortFruitBox(FruitBox &unsorted, FruitBox &lemons, FruitBox &bananas, FruitBox &limes)
{
    Fruit *fruit;
    FruitBox tmp(unsorted.nbFruits());
	bool success = false;

    while ((fruit = unsorted.pickFruit()))
        tmp.putFruit(fruit);
    while ((fruit = tmp.pickFruit())) {
		if (fruit->getVitamins() == 5)
			success = bananas.putFruit(fruit);
		else if (fruit->getVitamins() == 3)
			success = lemons.putFruit(fruit);
		else if (fruit->getVitamins() == 2)
			success = limes.putFruit(fruit);
		if (!success)
			unsorted.putFruit(fruit);
    }
}

FruitBox * const *LittleHand::organizeCoconut(Coconut const * const *coconuts)
{   
    if (!coconuts)
		return NULL;
	size_t box_num = 0;
	FruitBox **res = nullptr;
	FruitBox **temp;
	while (*coconuts) 
	{
		temp = new FruitBox*[box_num + 1];
		memcpy(temp, res, box_num * sizeof(*temp));
		delete[] res;
		res = temp;
		res[box_num] = new FruitBox(6);
		for (int i = 0; i < 6 && *coconuts; i++)
			res[box_num]->putFruit(*coconuts++);
		box_num++;
	}
	temp = new FruitBox*[box_num + 1];
	memcpy(temp, res, box_num * sizeof(*temp));
	delete[] res;
	temp[box_num] = nullptr;
	return (temp);
}