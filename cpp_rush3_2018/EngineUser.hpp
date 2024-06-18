/*
** EPITECH PROJECT, 2019
** EngineUser.hpp
** File description:
** EngineUser
*/

#ifndef ENGINEUSER_HPP_
	#define ENGINEUSER_HPP_

    #include <string>
    #include "IMonitorModule.hpp"

    class EngineUser : public IMonitorModule
    {
        public:
            EngineUser();
            virtual ~EngineUser();
            EngineUser& operator=(EngineUser const &);

            std::string	obtainMachineName() const;
            std::string	obtainUserName() const;
            std::string	obtainOpSys() const;
            std::string	obtainKernel() const;
            std::string	obtainDate() const;
            std::string	obtainTime() const;

            void defineMachineName(std::string);
            void defineUserName(std::string);
            void defineOpSys(std::string);
            void defineKernel(std::string);
            void defineDate(std::string);
            void defineTime(std::string);

        private:
            std::string	_machineName;
            std::string	_userName;
            std::string	_opSys;
            std::string	_kernel;
            std::string	_date;
            std::string	_time;
    };

#endif /* !ENGINEUSER_HPP_ */