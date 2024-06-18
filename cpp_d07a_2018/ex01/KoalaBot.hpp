/*
** EPITECH PROJECT, 2019
** KoalaBot.hh
** File description:
** @epitech.eu
*/

#ifndef KOALABOT_HH_
    #define KOALABOT_HH_

    #include <string>

    #include "Parts.hpp"

    class KoalaBot {
        public:
            KoalaBot(std::string serial = "Bob-01");
            ~KoalaBot();

            void setParts(Arms&);
            void setParts(Legs&);
            void setParts(Head&);

            void swapParts(Arms&);
            void swapParts(Legs&);
            void swapParts(Head&);

            const void informations();
            const bool status();
        private:
            std::string _serial;
            Arms _arms;
            Legs _legs;
            Head _head;
    };

#endif /* !KOALABOT_HH_ */