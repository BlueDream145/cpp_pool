/*
** EPITECH PROJECT, 2019
** DeepCoreMiner.hpp
** File description:
** @epitech.eu
*/

#ifndef DEEPCOREMINER_HPP_
    #define DEEPCOREMINER_HPP_

    #include "IMiningLaser.hpp"

    class DeepCoreMiner : public IMiningLaser {
        public:
            DeepCoreMiner();
            ~DeepCoreMiner();
            virtual void mine(IAsteroid*);
    };

#endif /* !DEEPCOREMINER_HPP_ */