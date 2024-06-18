/*
** EPITECH PROJECT, 2019
** koaladoctor.h
** File description:
** @epitech.eu
*/

#ifndef KOALADOCTOR_H_
    #define KOALADOCTOR_H_

    #include <string>
    
    #include "SickKoala.hpp"

    class KoalaDoctor {
        private:
            std::string name;
            bool active;
        public:
            KoalaDoctor(std::string name);
            ~KoalaDoctor();
            void diagnose(SickKoala *koala);
            void timeCheck();
    };

#endif /* !KOALADOCTOR_H_ */