/*
** EPITECH PROJECT, 2019
** EngineLineDisplay.cpp
** File description:
** EngineLineDisplay
*/

#include <iostream>
#include <string>
#include "EngineInfos.hpp"
#include "Engine.hpp"
#include "EngineUser.hpp"

void updateInfos(EngineInfos &infos);

void display(EngineInfos &infos)
{
    updateInfos(infos);
    std::cout << "### NETWORK ###" << std::endl;
    std::cout << "Up : " << infos._network.getUp() << std::endl;
    std::cout << "Down : " << infos._network.getDown() << std::endl << std::endl;

    std::cout << "### CORE ###" << std::endl;
    std::cout << "Central Process Unit Model : " << infos._core.obtainCPUModel() << std::endl;
    std::cout << "Core Number : " << infos._core.obtainCoreNb() << std::endl;
    std::cout << "Core 1 : " << infos._core.obtainCorePercent()[0] << std::endl;
    std::cout << "Core 2 : " << infos._core.obtainCorePercent()[1] << std::endl;
    std::cout << "Core 3 : " << infos._core.obtainCorePercent()[2] << std::endl;
    std::cout << "Core 4 : " << infos._core.obtainCorePercent()[3] << std::endl;
    std::cout << "Random Access Memory : " << infos._core.obtainRam()[0] << "/" << infos._core.obtainRam()[1] << std::endl;
    std::cout << "Swap : " << infos._core.obtainSwap()[0] << "/" << infos._core.obtainSwap()[1] << std::endl;
    std::cout << "Tasks Number : " << infos._core.obtainNbTasks() << std::endl << std::endl;

    std::cout << "### USER ###" << std::endl;
    std::cout << "Machine Name : " << infos._user.obtainMachineName() << std::endl;
    std::cout << "User Name : " << infos._user.obtainUserName() << std::endl;
    std::cout << "Operating System : " << infos._user.obtainOpSys() << std::endl;
    std::cout << "Kernel : " << infos._user.obtainKernel() << std::endl;
    std::cout << "Date : " << infos._user.obtainDate() << std::endl;
    std::cout << "Time : " << infos._user.obtainTime() << std::endl << std::endl;
}