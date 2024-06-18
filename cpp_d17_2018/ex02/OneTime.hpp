/*
** EPITECH PROJECT, 2019
** OneTime.hpp
** File description:
** @epitech.eu
*/

#ifndef ONETIME_HPP_
	#define ONETIME_HPP_

    #include <string>

    #include "IEncryptionMethod.hpp"

    class OneTime : public IEncryptionMethod {
        public:
            OneTime(std::string);
            virtual ~OneTime();

            virtual void encryptChar(char);
            virtual void decryptChar(char);
            virtual void reset();
        protected:
            std::string key;
            int index;
    };

#endif /* !ONETIME_HPP_ */