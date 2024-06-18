/*
** EPITECH PROJECT, 2019
** Encryption.hpp
** File description:
** @epitech.eu
*/

#ifndef ENCRYPTION_HPP_
	#define ENCRYPTION_HPP_

    #include <string>
    #include <iostream>
    #include <algorithm>

    #include "IEncryptionMethod.hpp"

    typedef void (IEncryptionMethod::*IEMethod)(char);

    class Encryption {
        public:
            Encryption(IEncryptionMethod &, IEMethod);
            virtual ~Encryption();

            void operator()(char);

            static void encryptString(IEncryptionMethod & encryptionMethod, std::string const &);
            static void decryptString(IEncryptionMethod & encryptionMethod, std::string const &);

        protected:
            IEncryptionMethod * instance;
            IEMethod method;
    };

#endif /* !ENCRYPTION_HPP_ */