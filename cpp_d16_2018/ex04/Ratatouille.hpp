/*
** EPITECH PROJECT, 2019
** Ratatouille.hpp
** File description:
** @epitech.eu
*/

#ifndef RATATOUILLE_HPP_
	#define RATATOUILLE_HPP_

    #include <string>
    #include <sstream>

    class Ratatouille {
        public:
            Ratatouille();
            Ratatouille(const Ratatouille & source);
            virtual ~Ratatouille();

            Ratatouille & addVegetable(unsigned char vegetable);
            Ratatouille & addCondiment(unsigned int condiment);
            Ratatouille & addSpice(double spice);
            Ratatouille & addSauce(std::string sauce);
            std::string kooc();

            Ratatouille & operator=(const Ratatouille & source);

        protected:
	        std::stringstream flux;
    };

#endif /* !RATATOUILLE_HPP_ */