/*
** EPITECH PROJECT, 2019
** Errors.hpp
** File description:
** @epitech.eu
*/

#ifndef ERRORS_HPP_
#define ERRORS_HPP_

#include <iostream>
#include <string>

class NasaError : public std::exception
{
    public:
        NasaError(std::string const &message,
                std::string const &component = "Unknown");
        virtual ~NasaError() throw() {}
        std::string const &getComponent() const;
        const char *what() const noexcept;
    private:
        std::string _message;
        std::string _component;
};

class MissionCriticalError : public NasaError
{
    public:
        MissionCriticalError(std::string const &message,
                std::string const &component = "Unknown");
        virtual ~MissionCriticalError() throw() {}
};

class LifeCriticalError : public NasaError
{
    public:
        LifeCriticalError(std::string const &message,
                std::string const &component = "Unknown");
        virtual ~LifeCriticalError() throw() {}
};

class UserError : public NasaError
{
    public:
        UserError(std::string const &message,
                std::string const &component = "Unknown");
        virtual ~UserError() throw() {}
};

class CommunicationError : public NasaError
{
    public:
        CommunicationError(std::string const &message);
        virtual ~CommunicationError() throw() {}
};

#endif
