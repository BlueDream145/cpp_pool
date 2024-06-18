/*
** EPITECH PROJECT, 2019
** Object.hpp
** File description:
** @epitech.eu
*/

#ifndef OBJECT_HPP_
	#define OBJECT_HPP_

    #include <string>

    class Object
    {
        protected:
            const std::string title;
        public:
            Object(const std::string &);
            virtual ~Object();
            const std::string &getTitle() const;
    };

#endif /* !OBJECT_HPP_ */
