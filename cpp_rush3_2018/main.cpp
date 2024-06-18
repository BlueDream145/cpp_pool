/*
** EPITECH PROJECT, 2019
** main.cpp
** File description:
** main
*/

#include "EngineInfos.hpp"
#include "EngineTextDisplay.hpp"
#include "EngineDisplay.hpp"
#include "Engine.hpp"
#include "EngineUser.hpp"
#include "EngineNetwork.hpp"

#include <iostream>

void updateInfos(EngineInfos &infos)
{
    initEngineUser(infos);
    initEngine(infos);
    initEngineNetwork(infos);
    infos._core.defineCoreNb(4);
}

std::string fill_env(char **env)
{
    const char *user = "USER=";
    std::string name = "ERROR"; 
    int size = 0;

    for (int i = 0; env[i] != NULL; i++) {
        std::string line = env[i];
        if (line.find(user) != line.npos) {
            size = line.length();
            name = line.substr(5, size);
        }
    }
    return(name);
}

void help()
{
    std::cout << "2019 Epitech Rush3" << std::endl;
    std::cout << "-g            Display graphical application" << std::endl;
    std::cout << "-h --help     Print help" << std::endl;
}

int	main(int ac, char ** av, char **env)
{
    EngineInfos *infos = new EngineInfos;
    std::string	user_name = fill_env(env);

    infos->_user.defineUserName(user_name);
    if (ac == 1)
        textDisplay(*infos);
    else if ((std::string) av[1] == "-g")
        graphDisplay(*infos);
    else
        help();
    delete infos;
    return(0);
}