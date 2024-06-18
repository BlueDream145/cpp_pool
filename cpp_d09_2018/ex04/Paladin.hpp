/*
** EPITECH PROJECT, 2019
** Paladin.hpp
** File description:
** @epitech.eu
*/

#ifndef PALADIN_HPP_
    #define PALADIN_HPP_

    #include "Warrior.hpp"
    #include "Priest.hpp"

    class Paladin : public Warrior, virtual public Priest {
        public:
            explicit Paladin(std::string const & name, int lvl);
            ~Paladin();
            virtual int RangeAttack();
            virtual int CloseAttack();
            virtual void Heal();
            virtual int Intercept();
        protected:
            Paladin();
            const static int defaultForce = 9;
            const static int defaultEndurance = 10;
            const static int defaultIntelligence = 10;
            const static int defaultEsprit = 10;
            const static int defaultAgilite = 2;

            const static int baseAtkClose = 20;
            const static int costAtkClose = 30;
            const static int baseAtkRange = 20;
            const static int costAtkRange = 25;
            const static int baseRestorePv = 70;
            const static int baseRestorePm = 100;
    };

#endif /* !PALADIN_HPP_ */