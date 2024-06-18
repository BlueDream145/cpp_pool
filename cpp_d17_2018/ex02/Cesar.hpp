/*
** EPITECH PROJECT, 2019
** Cesar.hpp
** File description:
** @epitech.eu
*/

#ifndef CESAR_HPP_
	#define CESAR_HPP_

    #include "IEncryptionMethod.hpp"

    class Cesar : public IEncryptionMethod
    {
        public:
            Cesar();
            virtual ~Cesar();

            virtual void encryptChar(char);
            virtual void decryptChar(char);
            virtual void reset();
        protected:
            int decal;
    };

#endif /* !CESAR_HPP_ */
