/*
** EPITECH PROJECT, 2019
** EngineNetwork.hpp
** File description:
** EngineNetwork
*/

#ifndef ENGINENETWORK_HPP_
	#define ENGINENETWORK_HPP_

    class EngineNetwork {
        public:
            EngineNetwork();
            ~EngineNetwork();

            void setUp(long long int);
            void setDown(long long int);

            long long int getUp() const;
            long long int getDown() const;
        private:
            long long int _up;
            long long int _down;
    };
    
#endif /* !ENGINENETWORK_HPP_ */