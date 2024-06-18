/*
** EPITECH PROJECT, 2019
** ex03.hpp
** File description:
** @epitech.eu
*/

#ifndef EX03_HPP_
	#define EX03_HPP_

    #include <iostream>

    template<typename T>
    void foreach(const T * tab, void (func)(const T &), int size)
    {
        for (int i = 0; i < size; i++)
            (*func)(tab[i]);
    }

    template<typename T>
    void print(const T & a)
    {
        std::cout << a << std::endl;
    }

#endif /* !EX03_HPP_ */