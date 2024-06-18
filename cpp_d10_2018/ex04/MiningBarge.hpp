/*
** EPITECH PROJECT, 2019
** MiningBarge.hpp
** File description:
** @epitech.eu
*/

#ifndef MININGBARGE_HPP_
    #define MININGBARGE_HPP_

    #include "IAsteroid.hpp"
    #include "IMiningLaser.hpp"

    class MiningBarge {
        public:
            MiningBarge();
            ~MiningBarge();

            void equip(IMiningLaser*);
            void mine(IAsteroid*) const;

        protected:
            IMiningLaser *lasers[4];
    };

#endif /* !MININGBARGE_HPP_ */