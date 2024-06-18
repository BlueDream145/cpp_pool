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
            virtual ~FruitBox();

            int nbFruits() const;
            bool putFruit(Fruit*);
            Fruit *pickFruit();
            FruitNode *head() const;
        protected:
            int _size;
            int _count;
            FruitNode *_header;
        private:
    };

#endif /* !FRUITBOX_HPP_ */