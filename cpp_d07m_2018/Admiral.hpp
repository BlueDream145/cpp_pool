/*
** EPITECH PROJECT, 2019
** Admiral.hpp
** File description:
** @epitech.eu
*/

#ifndef ADMIRAL_HPP_
    #define ADMIRAL_HPP_

    #include <string>
    #include <iostream>

    namespace Federation {
        namespace Starfleet {
            class Admiral;
        };
    };

    #include "Federation.hpp"
    #include "Borg.hpp"

    namespace Federation {
        namespace Starfleet {
            class Admiral {
                public:
                    Admiral(std::string);
                    ~Admiral();
                    bool (Federation::Starfleet::Ship::*movePtr)(Destination);
                    void (Federation::Starfleet::Ship::*firePtr)(Borg::Ship *);
                    bool move(Federation::Starfleet::Ship *, Destination);
                    void fire(Federation::Starfleet::Ship *, Borg::Ship *);
                private:
                    std::string _name;
            };
        };
    };

#endif /* !ADMIRAL_HPP_ */