/*
** EPITECH PROJECT, 2019
** MyAlgorithms.hpp
** File description:
** @epitech.eu
*/

#ifndef MYALGORITHMS_HPP_
	#define MYALGORITHMS_HPP_

    #include <algorithm>
    #include <iostream>
    #include <iomanip>

    template<typename T>
    void vPrint(T const& obj, void (*showFuncPtr)(int))
    {
        std::cout << "Dump (" << std::setw(2) << obj.size() << ')' << ' ';
        std::for_each(obj.begin(), obj.end(), showFuncPtr);
        std::cout << std::endl;
    }

    template<typename T>
    size_t vHowMany(T const& obj, int val)
    {
        return(std::count(obj.begin(), obj.end(), val));
    }

    template<typename T>
    bool vIsSimilar(T const& obj, int* vals)
    {
        return(std::equal(obj.begin(), obj.end(), vals));
    }

    template<typename T>
    void vAssign(T itFrom, T type, int val)
    {
        std::fill(itFrom, type, val);
    }

    template<typename T>
    void vFindAndModify(T& obj, int oldval, int newval)
    {
        std::replace(obj.begin(), obj.end(), oldval, newval);
    }

    template<typename T>
    typename T::iterator vFindAndKill(T& obj, int val)
    {
        return(std::remove(obj.begin(), obj.end(), val));
    }

    template<typename T>
    void vShift(T& obj, int nb)
    {
        std::rotate(obj.begin(), obj.begin() + nb, obj.end());
    }

    template<typename T, typename U>
    void vApply(T itFrom, T type, U funcPtr)
    {
        std::for_each(itFrom, type, funcPtr);
    }

    template<typename T>
    void vFlip(T& obj)
    {
        std::reverse(obj.begin(), obj.end());
    }

    template<typename T>
    void vToAscOrder(T& obj)
    {
        std::sort(obj.begin(), obj.end());
    }

    template<typename T>
    void vToSpecificOrder(T& obj, bool (*cmpFuncPtr)(int, int))
    {
        std::sort(obj.begin(), obj.end(), cmpFuncPtr);
    }

    template<typename T>
    typename T::iterator vGiveMeTheFirst(T& obj, int val)
    {
        return(std::find(obj.begin(), obj.end(), val));
    }

    template<typename T>
    typename T::iterator vRemoveDuplicate(T& obj)
    {
        return(std::unique(obj.begin(), obj.end()));
    }

    template<typename T>
    void vFusionOrderedLists(T const & objIn1, T const & objIn2, T& objOut)
    {
        std::merge(objIn1.begin(), objIn1.end(), objIn2.begin(), objIn2.end(), objOut.begin());
    }

#endif /* !MYALGORITHMS_HPP_ */