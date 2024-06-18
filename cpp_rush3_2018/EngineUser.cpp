/*
** EPITECH PROJECT, 2019
** EngineUser.cpp
** File description:
** EngineUser
*/

#include <sys/utsname.h>
#include <iostream>
#include <fstream>
#include <string>

#include "EngineInfos.hpp"
#include "EngineUser.hpp"

// Builder / Destructor

EngineUser::EngineUser()
{
}

EngineUser::~EngineUser()
{
}

// Operator

EngineUser& EngineUser::operator=(EngineUser const &other)
{
    this->_machineName = other._machineName;
    this->_userName = other._userName;
    this->_opSys = other._opSys;
    this->_kernel = other._kernel;
    this->_date = other._date;
    this->_time = other._time;
    return (*this);
}

// Define Data

void EngineUser::defineMachineName(std::string machineName) { this->_machineName = machineName; }
void EngineUser::defineUserName(std::string userName) { this->_userName = userName; }
void EngineUser::defineOpSys(std::string opSys) { this->_opSys = opSys; }
void EngineUser::defineKernel(std::string kernel) { this->_kernel = kernel; }
void EngineUser::defineDate(std::string date) { this->_date = date; }
void EngineUser::defineTime(std::string time) { this->_time = time; }

// Obtain Data

std::string EngineUser::obtainMachineName() const { return (this->_machineName); }
std::string EngineUser::obtainUserName() const { return (this->_userName); }
std::string EngineUser::obtainOpSys() const { return (this->_opSys); }
std::string EngineUser::obtainKernel() const { return (this->_kernel); }
std::string EngineUser::obtainDate() const { return (this->_date); }
std::string EngineUser::obtainTime() const { return (this->_time); }

// Methods

void initEngineUser(EngineInfos & _info)
{
    sys_hostname(_info);
    sys_kernel(_info);
    sys_time(_info);
}

void sys_hostname(EngineInfos & _info)
{
    std::string _src = "/proc/sys/kernel/hostname";
    std::ifstream _file(_src.c_str(), std::ios::in);
    std::string _hostname = "ERROR";;

    if (_file)
        if (!_file.eof())
            std::getline(_file, _hostname);
    _file.close();
    _info._user.defineMachineName(_hostname);
}

void sys_kernel(EngineInfos & _info)
{
    struct utsname unameData;
    std::string k_name = "ERROR";
    std::string k_vers = "ERROR";

    if(uname(&unameData) != -1)
    {
        k_name = unameData.sysname;
        k_vers = unameData.release;
    }
    _info._user.defineOpSys(k_name);
    _info._user.defineKernel(k_vers);
}

void sys_time(EngineInfos & _info)
{
    std::string   _src = "/proc/driver/rtc";
    std::ifstream _file(_src.c_str(), std::ios::in);
    std::string   _line;
    std::string _time = "ERROR";
    std::string _day = "ERROR";

    if (_file)
        while(!_file.eof())
        {
            std::getline(_file, _line);
            if (_line.find("rtc_time") != _line.npos)
                _time = _line.substr (11,19);
            if (_line.find("rtc_date") != _line.npos)
                _day = _line.substr (11,21);
        }
    _file.close();
    _info._user.defineTime(_time);
    _info._user.defineDate(_day);
}
