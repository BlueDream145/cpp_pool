/*
** EPITECH PROJECT, 2019
** Box.hpp
** File description:
** @epitech.eu
*/

#ifndef BOX_HPP_
	#define BOX_HPP_
        
    #include "Wrap.hpp"
    #include "Object.hpp"

    class Box : public Wrap
    {
        public:
            Box();
            void closeMe();
            bool wrapMeThat(Object *obj);
    };

#endif /* !BOX_HPP_ */