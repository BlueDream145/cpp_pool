/*
** EPITECH PROJECT, 2019
** Character.hpp
** File description:
** @epitech.eu
*/

#ifndef CHARACTER_HPP_
    #define CHARACTER_HPP_

    #include <string>

    typedef enum AttackRange_e {
        AR_CLOSE,
        AR_RANGE
    } AttackRange;

    class Character {
        public:
            explicit Character(std::string const &name, int lvl);
            virtual ~Character();

            // Vars
            const static AttackRange CLOSE = AR_CLOSE;
            const static AttackRange RANGE = AR_RANGE;
            AttackRange Range;

            // Get
            virtual std::string const & getName() const;
            virtual int getLvl() const;
            virtual int getPv() const;
            virtual int getPower() const;
            virtual int getForce() const;
            virtual int getEndurance() const;
            virtual int getIntelligence() const;
            virtual int getEsprit() const;
            virtual int getAgilite() const;

            // Set
            virtual void changePv(int value);
            virtual void changePm(int value);

            // Actions
            virtual int CloseAttack();
            virtual int RangeAttack();
            virtual void Heal();
            virtual void RestorePower();
            virtual void TakeDamage(int damage);
        protected:
            Character();

            // Actions
            virtual bool actionCost(int cost);
            virtual void speak(std::string message) const;

            // Vars
            std::string name;
            std::string race;
            std::string weaponClose;
            std::string weaponRange;
            int lvl;
            int pv;
            int pm;
            int force;
            int endurance;
            int intelligence;
            int esprit;
            int agilite;
            int atkClose;
            int costClose;
            int atkRange;
            int costRange;
            int restorePv;
            int costPv;
            int restorePm;
            int costPm;
            int const bonusNull;
            int const Character::*bonusCloseAttack;
            int const Character::*bonusRangeAttack;
            int const Character::*bonusRestorePm;

            static const int defaultForce = 5;
            static const int defaultEndurance = 5;
            static const int defaultIntelligence = 5;
            static const int defaultEsprit = 5;
            static const int defaultAgilite = 5;

            static const int lifeMax = 100;
            static const int movMax = 100;
            static const int baseAtkClose = 10;
            static const int costAtkClose = 10;
            static const int baseAtkRange = 5;
            static const int costAtkRange = 10;
            static const int baseRestorePv = 50;
            static const int baseCostPv = 0;
            static const int baseRestorePm = 100;
            static const int baseCostPm = 0;
        private:
    };
    
    std::string int_to_string(int n);

#endif /* !CHARACTER_HPP_ */