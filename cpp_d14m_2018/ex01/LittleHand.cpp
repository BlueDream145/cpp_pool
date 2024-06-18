/*
** EPITECH PROJECT, 2019
** LittleHand.cpp
** File description:
** @epitech.eu
*/

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