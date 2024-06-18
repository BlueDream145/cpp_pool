/*
** EPITECH PROJECT, 2019
** KoalaSteroid.hpp
** File description:
** @epitech.eu
*/

#ifndef KOALASTEROID_HPP_
    #define KOALASTEROID_HPP_

    #include "IAsteroid.hpp"
    #include "IMiningLaser.hpp"
    #include "DeepCoreMiner.hpp"
    #include "StripMiner.hpp"

    class KoalaSteroid : public IAsteroid {
        public:
            KoalaSteroid();
            ~KoalaSteroid();

        virtual std::string beMined(IMiningLaser *laser) const;
        virtual std::string beMined(DeepCoreMiner *laser) const;
        virtual std::string beMined(StripMiner *laser) const;
        virtual std::string getName() const;
    };

#endif /* !KOALASTEROID_HPP_ */