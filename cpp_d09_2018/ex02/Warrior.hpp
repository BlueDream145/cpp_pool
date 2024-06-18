/*
** EPITECH PROJECT, 2019
** Warrior.hpp
** File description:
** @epitech.eu
*/

#ifndef WARRIOR_HPP_
    #define WARRIOR_HPP_

    #include "Character.hpp"

    class Warrior : public Character
    {
        public:
            Warrior(std::string const & name, int lvl);
            Warrior(std::string const & name, int lvl, std::string weaponName);
            Warrior();
            ~Warrior();
            int CloseAttack();
            int RangeAttack();
        private:
            std::string _weaponName;
        protected:
            static const int defaultForce = 12;
            static const int defaultEndurance = 12;
            static const int defaultIntelligence = 6;
            static const int defaultEsprit = 5;
            static const int defaultAgilite = 7;

            static const int lifeMax = 100;
            static const int movMax = 100;
            static const int baseAtkClose = 20;
            static const int costAtkClose = 30;
            static const int baseAtkRange = 0;
            static const int costAtkRange = 10;
            static const int baseRestorePv = 50;
            static const int baseCostPv = 0;
            static const int baseRestorePm = 100;
            static const int baseCostPm = 0;
    };

#endif /* !WARRIOR_HPP_ */