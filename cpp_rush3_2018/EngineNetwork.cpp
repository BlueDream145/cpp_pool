/*
** EPITECH PROJECT, 2019
** EngineNetwork.cpp
** File description:
** EngineNetwork
*/

#include "EngineInfos.hpp"

#include "EngineNetwork.hpp"

EngineNetwork::EngineNetwork()
{
}

EngineNetwork::~EngineNetwork()
{
}

void EngineNetwork::setUp(long long int up)
{
    this->_up = up;
}

void EngineNetwork::setDown(long long int down)
{
    this->_down = down;
}

long long int EngineNetwork::getUp() const
{
    return(this->_up);
}

long long int EngineNetwork::getDown() const
{
    return(this->_down);
}

void initEngineNetwork(EngineInfos &infos)
{
    std::string src = "/proc/net/dev";
    std::string	line;
    std::ifstream file(src.c_str(), std::ios::in);
    int	max = 0;
    int	a = 0;
    int	i = 0;
    std::string	temp;

    while (std::getline(file, line))
    {
        if ((a = line.find(":")) != -1)
        {
            a++;
            while (line[a] == ' ')
                a++;
            while (line[a] != ' ')
            {
                temp += line[a];
                a++;
            }
            if (std::stoi(temp) > max)
            {
                infos._network.setUp(stoi(temp));
                temp.erase();
                while (i != 7)
                {
                    while (line[a] == ' ')
                        a++;
                    while (line[a] != ' ')
                        a++;
                    i++;
                }
                i = 0;
                while (line[a] == ' ')
                    a++;
                while (line[a] != ' ')
                {
                    temp += line[a];
                    a++;
                }
                infos._network.setDown(std::stoi(temp));
            }
        }
        temp.erase();
    }
    file.close();
}  