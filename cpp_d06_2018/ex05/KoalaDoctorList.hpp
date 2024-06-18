/*
** EPITECH PROJECT, 2019
** KoalaDoctorList.hpp
** File description:
** @epitech.eu
*/

#ifndef KOALADOCTORLIST_HPP_
	#define KOALADOCTORLIST_HPP_

    #include "KoalaDoctor.hpp"

    class KoalaDoctorList {
        public:
            KoalaDoctorList(KoalaDoctor*);
            ~KoalaDoctorList();
            KoalaDoctorList *getNext();
            void setNext(KoalaDoctorList *);
            void append(KoalaDoctorList *);
            KoalaDoctorList *remove(KoalaDoctorList*);
            KoalaDoctorList *removeFromName(std::string name);
            KoalaDoctor *getFromName(std::string name);
            KoalaDoctor *getContent();
            bool isEnd();
            void dump();
        private:
            std::string name;
            KoalaDoctor *content;
            KoalaDoctorList *next;
    };

#endif /* !KOALADOCTORLIST_HPP_ */