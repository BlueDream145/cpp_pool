/*
** EPITECH PROJECT, 2019
** skat.h
** File description:
** @epitech.eu
*/

#ifndef SKAT_H_
    #define SKAT_H_

    #include <string>
    #include <iostream>

    class Skat {
        private:
            std::string _name;
            int _stimPaks;
        public:
            Skat(std::string const&, int);
            Skat(std::string const&);
            Skat(int);
            Skat();
            ~Skat();
            int &stimPaks();
            const std::string &name() const;
            void shareStimPaks(int, int&);
            void addStimPaks(unsigned int);
            void useStimPaks();
            void status() const;
    };

#endif /* !SKAT_H_ */