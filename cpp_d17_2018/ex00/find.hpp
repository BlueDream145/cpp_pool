/*
** EPITECH PROJECT, 2019
** find.hpp
** File description:
** @epitech.eu
*/

#ifndef FIND_HPP_
	#define FIND_HPP_

    #include <algorithm>

    template<typename Obj>
    typename Obj::iterator do_find(Obj & ob, int nb)
    {
        return(std::find(ob.begin(), ob.end(), nb));
    }


#endif /* !FIND_HPP_ */