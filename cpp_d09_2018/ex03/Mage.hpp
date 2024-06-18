/*
** EPITECH PROJECT, 2019
** Mage.hpp
** File description:
** @epitech.eu
*/

#ifndef MAGE_HPP_
    #define MAGE_HPP_

    #include "Character.hpp"

    class Mage : public Character { 
        public:
            explicit Mage(std::string const & name, int lvl);
            virtual ~Mage();
            int CloseAttack();
            void RestorePower();
            int RangeAttack();
        protected:
            Mage();
            static const int defaultForce = 6;
            static const int defaultEndurance = 6;
            static const int defaultIntelligence = 12;
            static const int defaultEsprit = 11;
            static const int defaultAgilite = 7;

            static const int baseAtkClose = 0;
            static const int costAtkClose = 10;
            static const int baseAtkRange = 20;
            static const int costAtkRange = 25;
            static const int baseCostPv = 0;
            static const int baseRestorePm = 100;
            static const int baseCostPm = 0;
    };

#endif /* !MAGE_HPP_ */