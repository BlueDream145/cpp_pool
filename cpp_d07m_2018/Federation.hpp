/*
** EPITECH PROJECT, 2019
** federation.h
** File description:
** @epitech.eu
*/

#ifndef FEDERATION_H_
    #define FEDERATION_H_

    #include <iostream>
    #include <string>

    namespace Federation
    {
        namespace Starfleet
        {
            class Ship;
            class Captain;
            class Ensign;
        };
        class Ship;
    };

    #include "WarpSystem.hpp"
    #include "Borg.hpp"
    #include "Destination.hpp"

    namespace Federation
    {
        namespace Starfleet
        {
            class Captain
            {
                private:
                    std::string _name;
                    int _age;
                public:
                    Captain(std::string);
                    ~Captain();
                    std::string getName();
                    int getAge();
                    void setAge(int);
            };

            class Ensign
            {
                private:
                    std::string _name;
                    void speak(std::string);
                public:
                    explicit Ensign(std::string);
                    ~Ensign();
            };

            class Ship
            {
                private:
                    int _length;
                    int _width;
                    std::string _name;
                    short _maxWarp;
                    WarpSystem::Core *_core;
                    Federation::Starfleet::Captain *capt;
                    Destination _location;
                    Destination _home;
                    int _shield;
                    int _photonTorpedo;
                    Captain *_captain;
                public:
                    Ship(int, int, std::string, short, int);
                    Ship(int, int, std::string, short);
                    Ship();
                    ~Ship();

                    // Get Data
                    int getShield();
                    int getLength();
                    int getWidth();
                    int getPhotonTorpedo();
                    short getMaxWarp();
                    std::string getName();
                    WarpSystem::Core *getCore();
                    Captain *getCaptain();
                    Destination getLocation();
                    Destination getHome();
                    bool isStable();

                    // Set Data
                    void setShield(int);
                    void setHome(Destination);
                    void setCore(WarpSystem::Core *);
                    void setLocation(Destination);
                    void setPhotonTorpedo(int);

                    // Core
                    void setupCore(WarpSystem::Core*);
                    void checkCore();
                    void promote(Federation::Starfleet::Captain *);

                    // Actions
                    void fire(Borg::Ship *);
                    void fire(int torpedoes, Borg::Ship *);
                    void stricken(int);
                    bool move(int, Destination);
                    bool move(int);
                    bool move(Destination d);
                    bool move();
            };
        };

        class Ship
        {
            private:
                int _length;
                int _width;
                std::string _name;
                WarpSystem::Core *_core;
                Destination _location;
                Destination _home;
            public:
                Ship(int, int, std::string);
                ~Ship();

                // Get Data
                int getLength();
                int getWidth();
                short getMaxWarp();
                std::string getName();
                WarpSystem::Core *getCore();
                Destination getLocation();
                Destination getHome();
                bool getStable();

                // Set Data
                void setHome(Destination);
                void setCore(WarpSystem::Core *);
                void setLocation(Destination);

                // Core
                void setupCore(WarpSystem::Core*);
                void checkCore();

                // Actions
                bool move(int, Destination);
                bool move(int);
                bool move(Destination);
                bool move();
                void stricken(int);
        };
    };

#endif /* !FEDERATION_H_ */