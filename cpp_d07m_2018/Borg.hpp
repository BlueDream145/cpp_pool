/*
** EPITECH PROJECT, 2019
** borg.h
** File description:
** @epitech.eu
*/

#ifndef BORG_H_
    #define BORG_H_

    namespace Borg
    {
        class Ship;
    };

    #include "WarpSystem.hpp"
    #include "Federation.hpp"
    #include "Destination.hpp"

    namespace Borg
    {
        class Ship
        {
            private:
                int _side;
                int _shield;
                int _weaponFrequency;
                short _repair;
                short _maxWarp;
                WarpSystem::Core *_core;
                Destination _location;
                Destination _home;
            public:
                Ship(int frequency = 20, short repair = 3);
                ~Ship();

                // Get Data
                int getSide();
                int getShield();
                int getWeaponFrequency();
                short getRepair();
                short getMaxWarp();
                bool isStable();
                WarpSystem::Core *getCore();
                Destination getLocation();
                Destination getHome();

                // Set Data
                void setShield(int);
                void setCore(WarpSystem::Core *);
                void setLocation(Destination);
                void setHome(Destination);
                void setWeaponFrequency(int);
                void setRepair(short);

                // Core
                void setupCore(WarpSystem::Core *);
                void checkCore();

                // Actions
                bool move(int, Destination);
                bool move(int);
                bool move(Destination);
                bool move();
                void fire(Federation::Starfleet::Ship *);
                void fire(Federation::Ship *);
                void stricken(int);
                void repair();
        };
    };


#endif /* !BORG_H_ */