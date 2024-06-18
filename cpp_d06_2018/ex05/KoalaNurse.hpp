/*
** EPITECH PROJECT, 2019
** koalanurse.h
** File description:
** @epitech.eu
*/

#ifndef KOALANURSE_H_
    #define KOALANURSE_H_

    #include <iostream>
    #include <string>
    #include "SickKoala.hpp"

    class KoalaNurse {
        private:
            int id;
            bool work;
        public:
            KoalaNurse(int);
            ~KoalaNurse();
            void giveDrug(std::string, SickKoala *);
            void timeCheck();
            std::string readReport(std::string);
            int getID();
    };

#endif /* !KOALANURSE_H_ */