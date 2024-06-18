/*
** EPITECH PROJECT, 2019
** Container.hpp
** File description:
** @epitech.eu
*/

#ifndef CONTAINER_HPP_
	#define CONTAINER_HPP_

    #include <iostream>
    #include <algorithm>

    template<typename T>
    void aff(T value)
    {
        std::cout << "Value : " << value << std::endl;
    }

    template<typename T>
    void add(T & value)
    {
        value++;
    }

    template<typename T, template <typename, typename> class container>
    class contain
    {
        private:
            container<T, std::allocator<T> > _contain;
            T _val;
        public:
            void push(T val)
            {
                _contain.push_back(val);
            }

            void aff()
            {
                std::for_each(_contain.begin(), _contain.end(), &::aff<T>);
            }

            void add()
            {
                std::for_each(_contain.begin(), _contain.end(), &::add<T>);
            }
    };

#endif /* !CONTAINER_HPP_ */
