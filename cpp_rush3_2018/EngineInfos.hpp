/*
** EPITECH PROJECT, 2019
** EngineInfos.hpp
** File description:
** EngineInfos
*/

#ifndef EngineInfos_HPP_
	#define EngineInfos_HPP_

    #include <string>
    #include <fstream>

    #include "Engine.hpp"
    #include "EngineUser.hpp"
    #include "EngineNetwork.hpp"

    class EngineInfos
    {
        public:
            EngineInfos();
            ~EngineInfos();
            EngineInfos& operator=(EngineInfos const &);

            Engine _core;
            EngineUser _user;
            EngineNetwork	_network;
    };

    void initEngine(EngineInfos &);
    void initEngineUser(EngineInfos &);
    void initEngineCore(EngineInfos &);
    void initEngineNetwork(EngineInfos &);

    void sys_hostname(EngineInfos &);
    void sys_username(EngineInfos &);
    void sys_kernel(EngineInfos &);
    void sys_time(EngineInfos &);
    
    void display(EngineInfos &);

    float getCPUIdle(std::string);
    float getCPUNonIdle(std::string);
    float *fillCPUNonIdle(std::string);
    float *fillCPUIdle(std::string);

    void obtainLoadAvgFromFile(EngineInfos &);
    void obtainNbTasksFromFile(EngineInfos &);
    void obtainCPUInfo(EngineInfos &);
    void obtainRamInfo(struct sysinfo, EngineInfos &);
    void obtainSwapInfo(struct sysinfo, EngineInfos &);
    void obtainCorePercentFromFile(EngineInfos &);
    std::string	parsingCPU(const std::string, const std::string, const std::string);

#endif /* !EngineInfos_HPP_ */