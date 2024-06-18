/*
** EPITECH PROJECT, 2019
** FruitBox.hpp
** File description:
** @epitech.eu
*/

#ifndef FRUITBOX_HPP_
	#define FRUITBOX_HPP_

    #include "Fruit.hpp"
    #include "FruitNode.hpp"

    class FruitBox {
        public:
            FruitBox(int);
            ~FruitBox();

            int nbFruits() const;
            bool putFruit(Fruit*);
            Fruit *pickFruit();
            FruitNode *head() const;
        private:
            int _size;
            int _count;
            FruitNode *_header;
    };

#endif /* !FRUITBOX_HPP_ */