/*
** EPITECH PROJECT, 2019
** droid.hh
** File description:
** @epitech.eu
*/

#ifndef DROID_HH_
    #define DROID_HH_

    #include <string>
    #include <iostream>
    #include <algorithm>

    class Droid {
        private:
            std::string _id;
            size_t _energy;
            const size_t _attack;
            const size_t _toughness;
            std::string *_status;
        public:
            Droid(std::string id = "");
            Droid(Droid const&);
            ~Droid();

            std::string getId() const;
            size_t getEnergy() const;
            size_t getAttack() const;
            size_t getToughness() const;
            std::string *getStatus() const;

            void setId(std::string);
            void setEnergy(size_t);
            void setStatus(std::string*);

            void speak(std::string);
            void speak_silent(std::string);
            Droid& operator=(Droid const&);

            bool operator==(Droid const &) const;
            bool operator!=(Droid const &) const;

            Droid& operator<<(size_t &);
    };

    std::ostream & operator<<(std::ostream & os, const Droid & droid);

#endif /* !DROID_HH_ */