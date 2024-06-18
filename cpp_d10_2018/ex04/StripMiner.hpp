/*
** EPITECH PROJECT, 2019
** StripMiner.hpp
** File description:
** @epitech.eu
*/

#ifndef STRIPMINER_HPP_
    #define STRIPMINER_HPP_

    #include "IMiningLaser.hpp"

    class StripMiner : public IMiningLaser {
        public:
            StripMiner();
            ~StripMiner();

        void mine(IAsteroid*);
    };

#endif /* !STRIPMINER_HPP_ */