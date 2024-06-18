/*
** EPITECH PROJECT, 2019
** carrier.hpp
** File description:
** @epitech.eu
*/

#ifndef CARRIER_HPP_
    #define CARRIER_HPP_

    #include "Droid.hpp"

    class Carrier {
        private:
            std::string id;
            size_t energy;
            size_t const attack;
            size_t const toughness;
            Droid **droids;
            Carrier(Carrier const &);
        public:
            Carrier(std::string);
            ~Carrier();

            std::string getId() const;
            size_t getEnergy() const;
            size_t getAttack() const;
            size_t getToughness() const;
            size_t getSpeed() const;
            size_t getNbDroids() const;

            void setId(std::string id);
            void setEnergy(size_t energy);

            Droid *&operator[](int position) const;
            bool operator()(int x, int y);
            Carrier &operator<<(size_t &energy);
            Carrier &operator<<(Droid *droid);
            Carrier &operator>>(Droid *droid);
            Carrier &operator~();
    };

    std::ostream & operator<<(std::ostream &os, Carrier const & carrier);

#endif /* !CARRIER_HPP_ */