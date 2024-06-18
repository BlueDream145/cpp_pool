/*
** EPITECH PROJECT, 2019
** SIckKoalaList.hpp
** File description:
** @epitech.eu
*/

#ifndef SICKKOALALIST_HPP_
    #define SICKKOALALIST_HPP_

    #include "SickKoala.hpp"

    class SickKoalaList {
        public:
            SickKoalaList(SickKoala* koala);
            ~SickKoalaList();
            bool isEnd();
            void append(SickKoalaList *list);
            SickKoalaList *remove(SickKoalaList *list);
            SickKoalaList *removeFromName(std::string koalaName);
            SickKoala *getContent();
            SickKoalaList *getNext();
            std::string getName();
            void setNext(SickKoalaList *list);
            void dump();
        private:
            std::string name;
            SickKoala *content;
            SickKoalaList *next;
    };

#endif /* !SICKKOALALIST_HPP_ */