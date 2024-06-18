/*
** EPITECH PROJECT, 2019
** ex02.hpp
** File description:
** @epitech.eu
*/

#include <iostream>

#ifndef EX02_HPP_
	#define EX02_HPP_

    int min(int a, int b)
    {
        std::cout << "non-template min" << std::endl;
        if (a <= b)
            return(a);
        return(b);
    }

    template<typename T>
    const T & min(const T & a, const T & b)
    {
        std::cout << "template min" << std::endl;
        if (a <= b)
            return(a);
        return(b);
    }

    int nonTemplateMin(int * tab, int size)
    {
        int m = tab[0];
        for (int i = 1; i < size; i++)
            m = min(m, tab[i]);
        return(m);
    }

    template<typename T>
    const T & templateMin(const T * tab, int size) {
        T & m = const_cast<T&>(tab[0]);
        for (int i = 1; i < size; i++)
            m = min<T>(m, tab[i]);
        return(m);
    }

#endif /* !EX02_HPP_ */