/*
** EPITECH PROJECT, 2019
** LittleHand.hpp
** File description:
** @epitech.eu
*/

#ifndef LITTLEHAND_HPP_
	#define LITTLEHAND_HPP_

    #include "Coconut.hpp"
    #include "FruitBox.hpp"

    class LittleHand {
        public:
            LittleHand();
            ~LittleHand();
            static void sortFruitBox(FruitBox &, FruitBox &, FruitBox &, FruitBox &);
            static FruitBox * const *LittleHand::organizeCoconut(Coconut const * const *coconuts);
    };

#endif /* !LITTLEHAND_HPP_ */