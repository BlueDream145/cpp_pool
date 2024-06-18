/*
** EPITECH PROJECT, 2019
** LittleHand.hpp
** File description:
** @epitech.eu
*/

#ifndef LITTLEHAND_HPP_
	#define LITTLEHAND_HPP_

    #include "FruitBox.hpp"

    class LittleHand {
        public:
            LittleHand();
            ~LittleHand();
            static void sortFruitBox(FruitBox &, FruitBox &, FruitBox &, FruitBox &);
    };

#endif /* !LITTLEHAND_HPP_ */