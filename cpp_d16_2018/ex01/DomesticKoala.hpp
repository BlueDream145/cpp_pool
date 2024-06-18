/*
** EPITECH PROJECT, 2019
** DomesticKoala.hpp
** File description:
** @epitech.eu
*/

#ifndef DOMESTICKOALA_HPP_
	#define DOMESTICKOALA_HPP_

    #include <iostream>
    #include <string>
    #include <map>
    #include <vector>

    #include "KoalaAction.hpp"

    class DomesticKoala {
        public:
            typedef void (KoalaAction::*methodPointer_t)(const std::string&);
            DomesticKoala(KoalaAction&);
            DomesticKoala(const DomesticKoala &);
            ~DomesticKoala();
            
            DomesticKoala& operator=(const DomesticKoala&);
            std::vector<methodPointer_t> const * getAction(void) const;
            void learnAction(unsigned char, methodPointer_t);
            void unlearnAction(unsigned char);
            void doAction(unsigned char, const std::string&);
            void setKoalaAction(KoalaAction&);
        private:
            KoalaAction _action;
            std::vector<methodPointer_t> _knowAction;
    };

#endif /* !DOMESTICKOALA_HPP_ */