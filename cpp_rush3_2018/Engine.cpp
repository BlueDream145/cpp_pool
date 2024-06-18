/*
** EPITECH PROJECT, 2019
** Engine.cpp
** File description:
** Engine
*/

#include <string>
#include <vector>
#include <chrono>
#include <thread>
#include <sys/sysinfo.h>

#include "EngineInfos.hpp"
#include "Engine.hpp"

static std::string PATH = "/proc/";

// Builder / Constructor

Engine::Engine()
{
}

Engine::~Engine()
{
}


// Operator

Engine & Engine::operator=(Engine const &other)
{
    this->defineCoreNb(other.obtainCoreNb());
    this->defineCorePercent(other.obtainCorePercent());
    this->defineRam(other.obtainRam());
    this->defineSwap(other.obtainSwap());
    this->defineNbTasks(other.obtainNbTasks());
    this->defineLoadAvg(other.obtainLoadAvg());
    return (*this);
}

// obtain data

std::string Engine::obtainCPUModel() const { return (this->_CPUModel); }
int	Engine::obtainCoreNb() const	{ return (this->_coreNb); }
float *Engine::obtainCorePercent() const	{ return (this->_corePercent); }
float *Engine::obtainRam() const	{ return (this->_ram); }
float *Engine::obtainSwap() const { return (this->_swap); }
int	Engine::obtainNbTasks() const { return (this->_nbTasks); }
float *Engine::obtainLoadAvg() const { return (this->_loadAvg); }

// define data
void Engine::defineCPUModel(std::string model) { this->_CPUModel = model; }
void Engine::defineCoreNb(int coreNb) { this->_coreNb = coreNb; }
void Engine::defineCorePercent(float *corePercent) { this->_corePercent = corePercent; }
void Engine::defineRam(float *ram) { this->_ram = ram; }
void Engine::defineSwap(float *swap) { this->_swap = swap; }
void Engine::defineNbTasks(int tasksNb) { this->_nbTasks = tasksNb; }
void Engine::defineLoadAvg(float *loadAvg) { this->_loadAvg = loadAvg; }

// Init Engine

void initEngine(EngineInfos & inf)
{
    float res[2] = { 0.0, 0.0 };

    obtainLoadAvgFromFile(inf);
    obtainNbTasksFromFile(inf);
    obtainCPUInfo(inf);
    obtainCorePercentFromFile(inf);
    struct sysinfo sys;
    if (!sysinfo(&sys))
    {
        obtainRamInfo(sys, inf);
        obtainSwapInfo(sys, inf);
    }
    else
    {
        inf._core.defineRam(res);
        inf._core.defineSwap(res);
    }
}

// Methods

void obtainLoadAvgFromFile(EngineInfos & inf)
{
    const char *loadavg = "loadavg";
    int i = 0, j = 0;
    std::string src = PATH + loadavg;
    std::string line, str;
    std::ifstream file(src.c_str(), std::ios::in);
    float res[3] = {0.0, 0.0, 0.0};

    if (file)
    {
        getline(file, line);
        while (j < 3)
        {
            if (line[i] == ' ')
            {
                res[j] = std::stof(str);
                i++;
                j++;
                str = "";
            }
            str += line[i];
            i++;
        }
        inf._core.defineLoadAvg(res);
    }
    else
       inf._core.defineLoadAvg(res);
}

void obtainNbTasksFromFile(EngineInfos & inf)
{
    const char *loadavg = "loadavg";
    std::string path = PATH + loadavg;
    std::string line, str;
    std::ifstream file(path.c_str(), std::ios::in);
    int i = 0;

    if (file)
    {
        getline(file, line);
        for (;line[i] != '/'; i++);
        str += line[i-1];
        inf._core.defineNbTasks(std::stoi(str));
    }
    else
        inf._core.defineNbTasks(0);
}

float obtainCPUIdle(std::string line)
{
    int k = 0;
    float val = 0;
    std::string number;

    for (unsigned int i = 0; i < line.length(); i++)
        if (line[i] >= '0' && line[i] <= '9')
        {
            while (line[i] >= '0' && line[i] <= '9')
                number += line[i++];
            if (k == 3 || k == 4)
                val += std::stof(number);
            k++;
            number = "";
        }
    return(val);
}

float obtainCPUNonIdle(std::string line)
{
    int k = 0;
    float nonIdle = 0;
    std::string nb;

    for (unsigned int i = 0; i < line.length(); i++)
        if (line[i] >= '0' && line[i] <= '9')
        {
            while (line[i] >= '0' && line[i] <= '9')
                nb += line[i++];
            if (k != 3 && k != 4)
                nonIdle += std::stof(nb);
            nb = "";
            k++;
        }
    return(nonIdle);
}

float *fillCPUIdle(std::string src)
{
    const char *cpu = "cpu";
    int i, jump = 0, li = 0;
    float *ret = new float;
    std::string line;

    std::ifstream file(src.c_str(), std::ios::in);
    if (!file) {
        file.close();
        return(ret);
    }
    while (getline(file, line))
    {
        i = line.find(cpu);
        if (i != -1 && jump != 0)
        {
            switch (li++)
            {
                case 0:
                    ret[0] = obtainCPUIdle(line);
                    break;
                case 1:
                    ret[1] = obtainCPUIdle(line);
                    break;
                case 2:
                    ret[2] = obtainCPUIdle(line);
                    break;
                case 3:
                    ret[3] = obtainCPUIdle(line);
                    break;
            }
        }
        jump = 1;
    }
    file.close();
    return(ret);
}

float *fillCPUNonIdle(std::string src)
{
    const char *cpu = "cpu";
    int i, jump = 0, li = 0;
    float *ret = new float;
    std::string line;

    std::ifstream file(src.c_str(), std::ios::in);
    if (!file) {
        file.close();
        return (ret);
    }
    while (getline(file, line))
    {
        i = line.find(cpu);
        if (i != -1 && jump != 0)
        {
            switch (li++)
            {
                case 0:
                    ret[0] = obtainCPUNonIdle(line);
                    break;
                case 1:
                    ret[1] = obtainCPUNonIdle(line);
                    break;
                case 2:
                    ret[2] = obtainCPUNonIdle(line);
                    break;
                case 3:
                    ret[3] = obtainCPUNonIdle(line);
                    break;
            }
        }
        jump = 1;
    }
    file.close();
    return (ret);
}

void obtainCorePercentFromFile(EngineInfos & inf)
{
    const char *stat = "stat";
    std::string src = PATH + stat;
    float *ret = new float;
    float *prevIdle, *idle;
    float *prevNonIdle, *nonIdle;
    float *totald = new float;
    float *idled = new float;

    prevIdle = fillCPUIdle(src);
    prevNonIdle = fillCPUNonIdle(src);
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    idle = fillCPUIdle(src);
    nonIdle = fillCPUNonIdle(src);
    for (int i = 0; i < 4; i++)
    {
        totald[i] = nonIdle[i] - prevNonIdle[i];
        idled[i] = idle[i] - prevIdle[i];
        ret[i] = (totald[i] / (totald[i] + idled[i])) * 100;
    }
    inf._core.defineCorePercent(ret);
    delete(prevIdle);
    delete(idle);
    delete(prevNonIdle);
    delete(nonIdle);
    delete(totald);
    delete(idled);
}

std::string parsingCPU(const std::string str)
{
    unsigned int i = 0;
    std::string ret;

    while (str[i] != ':')
        i++;
    i += 2;
    while (i < str.length())
        ret += str[i++];
    return(ret);
}

void obtainCPUInfo(EngineInfos & inf)
{
    const char *cpu = "cpuinfo";
    const char *model = "model name";
    const char *processor = "processor";

    std::string path = PATH + cpu;
    std::string str, line;
    std::ifstream file(path.c_str(), std::ios::in);
    inf._core.defineCoreNb(0);
    if (file)
        while (getline(file, line))
            if (line.find(model) != std::string::npos)
               inf._core.defineCPUModel(parsingCPU(line));
            else if (line.find(processor) != std::string::npos)
               inf._core.defineCoreNb(inf._core.obtainCoreNb() + 1);
    else {
        inf._core.defineCPUModel("");
        inf._core.defineCoreNb(0);
    }
}

void obtainRamInfo(struct sysinfo sys, EngineInfos & inf)
{
    float total = (float)sys.totalram / (1024 * 1024 * 1024);
    float available = (float)sys.freeram / (1024 * 1024 * 1024);
    float used = total - available;
    float *ram = new float;
    
    ram[0] = used;
    ram[1] = total;
    inf._core.defineRam(ram);
}

void obtainSwapInfo(struct sysinfo sys, EngineInfos & inf)
{
    float total = (float)sys.totalswap / (1024 * 1024 * 1024);
    float available = (float)sys.freeswap / (1024 * 1024 * 1024);
    float used = total - available;
    float *swap = new float;

    swap[0] = used;
    swap[1] = total;
    inf._core.defineSwap(swap);
}