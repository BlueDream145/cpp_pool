/*
** EPITECH PROJECT, 2019
** Wrap.hpp
** File description:
** @epitech.eu
*/

#ifndef WRAP_HPP_
	#define WRAP_HPP_

    #include "Object.hpp"

    class Wrap : public Object
    {
        protected:
            Object *_obj;
            bool isOpen;
        public:
            Wrap(const std::string &);
            virtual ~Wrap();
            virtual bool wrapMeThat(Object *);
            void openMe();
            virtual void closeMe() = 0;
            Object *getObj();	
    };

#endif /* !WRAP_HPP_ */
