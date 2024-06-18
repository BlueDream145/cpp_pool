/*
** EPITECH PROJECT, 2019
** Picture.hpp
** File description:
** @epitech.eu
*/

#ifndef PICTURE_HPP_
	#define PICTURE_HPP_

    #include <string>

    class Picture {
        public:
            Picture();
            Picture(const std::string &);
            virtual ~Picture();

            std::string data;
            bool getPictureFromFile(const std::string &);
            Picture & operator=(Picture const &);
    };

#endif /* !PICTURE_HPP_ */