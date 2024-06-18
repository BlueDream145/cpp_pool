/*
** EPITECH PROJECT, 2019
** Priest.hpp
** File description:
** @epitech.eu
*/

#ifndef PRIEST_HPP_
    #define PRIEST_HPP_

    #include "Mage.hpp"

    class Priest : public Mage {
        public:
            explicit Priest(std::string const & name, int lvl);
            virtual ~Priest();

            virtual int CloseAttack();
            virtual void Heal();
        protected:
            Priest();
            static int const defaultForce = 4;
            static int const defaultEndurance = 4;
            static int const defaultIntelligence = 42;
            static int const defaultEsprit = 21;
            static int const defaultAgilite = 2;

            static int const baseAtkClose = 10;
            static int const baseRestorePv = 70;
            static int const baseCostPv = 10;
    };

#endif /* !PRIEST_HPP_ */