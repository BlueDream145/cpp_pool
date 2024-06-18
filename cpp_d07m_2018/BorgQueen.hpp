/*
** EPITECH PROJECT, 2019
** BorgQueen.h
** File description:
** @epitech.eu
*/

#ifndef BORGQUEEN_HH_
    #define BORGQUEEN_HH_

    namespace Borg {
        class BorgQueen;
    }

    #include "Borg.hpp"
    #include "Federation.hpp"

    namespace Borg {
        class BorgQueen {
            public:
                BorgQueen();
                ~BorgQueen();

                bool move(Borg::Ship*, Destination);
                void fire(Borg::Ship*, Federation::Starfleet::Ship*);
                void destroy(Borg::Ship*, Federation::Ship*);

                bool (Borg::Ship::*movePtr)(Destination);
                void (Borg::Ship::*firePtr)(Federation::Starfleet::Ship *);
                void (Borg::Ship::*destroyPtr)(Federation::Ship *);
        };
    };

#endif /* !BORGQUEEN_HH_ */