/*
** EPITECH PROJECT, 2019
** BF_Translator.hpp
** File description:
** @epitech.eu
*/

#ifndef BF_TRANSLATOR_HPP_
	#define BF_TRANSLATOR_HPP_

    #include <string>
    #include <fstream>
    #include <map>

    class BF_Translator {

        typedef void (BF_Translator::*bf_command)();

        public:
            BF_Translator();
            virtual ~BF_Translator();

            int translate(const std::string &, const std::string &);
        protected:
            std::fstream in;
            std::fstream out;
            std::map<char, bf_command> commands;

            void fileHeader();
            void fileFooter();
            void memoryUp();
            void memoryDown();
            void cursorUp();
            void cursorDown();
            void writeMemory();
            void readMemory();
            void loopMemory();
            void backFile();
    };

#endif /* !BF_TRANSLATOR_HPP_ */