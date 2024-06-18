/*
** EPITECH PROJECT, 2019
** Parser.c
** File description:
** @epitech.eu
*/

#include <sstream>
#include <string>

#include "Parser.hpp"

Parser::Parser()
{
	_result = 0;
}

Parser::Parser(const Parser & source)
{
	trash = source.trash;
	output = source.output;
	_result = source._result;
}

Parser::~Parser()
{
}

Parser & Parser::operator=(Parser const &P)
{
    trash = P.trash;
    output = P.output;
    _result = P._result;
    return *this;
}

void Parser::dispatchOperator(int tmp_f, int tmp_s)
{
    switch (trash.top())
    {
        case '+' :
            output.push(tmp_s + tmp_f);
            break;
        case '-' :
            output.push(tmp_s - tmp_f);
            break;
        case '*' :
            output.push(tmp_s * tmp_f);
            break;
        case '/' :
            output.push(tmp_s / tmp_f);
            break;
        case '%' :
            output.push(tmp_s % tmp_f);
            break;
        default:
            break;
    }
}

void Parser::feed(const std::string & op)
{
    unsigned int i(0);
    std::string tmp_nb;
    int	tmp_f;
    int	tmp_s;

    while (i < op.size())
    {
        tmp_nb.clear();
        if (op[i] >= '0' && op[i] <= '9')
        {
            while (op[i] >= '0' && op[i] <= '9')
                tmp_nb += op[i++];
            std::stringstream(tmp_nb) >> tmp_f;
            output.push(tmp_f);
        }
        else if (op[i] == '+' || op[i] == '-'
                || op[i] == '*' || op[i] == '/'
                || op[i] == '%' || op[i] == '(')
        {
            trash.push(op[i]);
            i++;
        }
        else if (op[i] == ')')
        {
            i++;
            while (trash.top() != '(')
            {
                tmp_f = output.top();
                output.pop();
                tmp_s = output.top();
                output.pop();
                dispatchOperator(tmp_f, tmp_s);
                trash.pop();
            }
            trash.pop();
        }
        else
            i++;
    }
    while (!trash.empty())
    {
        tmp_f = output.top();
        output.pop();
        tmp_s = output.top();
        output.pop();
        dispatchOperator(tmp_f, tmp_s);
        trash.pop();
    }
    _result += output.top();
    output.pop();
}

int Parser::result() const
{
	return(_result);
}

void Parser::reset()
{
	std::stack<char> cleartrash;
    std::stack<int> clearoutput;

	trash = cleartrash;
	output = clearoutput;
	_result = 0;
}