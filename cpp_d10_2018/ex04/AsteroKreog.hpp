/*
** EPITECH PROJECT, 2019
** AsteroKreog.hpp
** File description:
** @epitech.eu
*/

#ifndef ASTEROKREOG_HPP_
    #define ASTEROKREOG_HPP_

    #include <string>

    #include "IAsteroid.hpp"
    #include "IMiningLaser.hpp"

    class AsteroKreog : public IAsteroid {
        public:
            AsteroKreog();
            ~AsteroKreog();

            virtual std::string beMined(IMiningLaser*) const;
            virtual std::string beMined(DeepCoreMiner*) const;
            virtual std::string beMined(StripMiner*) const;
            virtual std::string getName() const;
    };

#endif /* !ASTEROKREOG_HPP_ */