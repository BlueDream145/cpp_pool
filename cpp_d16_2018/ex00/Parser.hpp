/*
** EPITECH PROJECT, 2019
** Parser.hpp
** File description:
** @epitech.eu
*/

#ifndef PARSER_HPP_
	#define PARSER_HPP_

    #include <string>
    #include <stack>

    class Parser {
        public:
            Parser();
            Parser(const Parser & source);
            virtual ~Parser();

            Parser & operator=(Parser const&);
            void feed(const std::string &);
            int result() const;
            void reset();
            void dispatchOperator(int, int);
        protected:
            std::stack<char> trash;
            std::stack<int> output;
            int _result;
    };

#endif /* !PARSER_HPP_ */