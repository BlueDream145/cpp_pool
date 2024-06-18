/*
** EPITECH PROJECT, 2019
** KoalaNurseList.hpp
** File description:
** @epitech.eu
*/

#ifndef KOALANURSELIST_HPP_
    #define KOALANURSELIST_HPP_

    #include "KoalaNurse.hpp"

    class KoalaNurseList {
        public:
            KoalaNurseList(KoalaNurse*);
            ~KoalaNurseList();
            KoalaNurseList *getNext();
            void setNext(KoalaNurseList *);
            void append(KoalaNurseList *);
            KoalaNurseList *remove(KoalaNurseList*);
            KoalaNurseList *removeFromID(int);
            KoalaNurse *getFromID(int id);
            KoalaNurse *getContent();
            bool isEnd();
            void dump();
        private:
            KoalaNurse *content;
            KoalaNurseList *next;
    };

#endif /* !KOALANURSELIST_HPP_ */