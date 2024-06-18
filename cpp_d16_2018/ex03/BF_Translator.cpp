/*
** EPITECH PROJECT, 2019
** BF_Translator.cpp
** File description:
** @epitech.eu
*/

#include "BF_Translator.hpp"

BF_Translator::BF_Translator()
{
	commands['+'] = &BF_Translator::memoryUp;
	commands['-'] = &BF_Translator::memoryDown;
	commands['>'] = &BF_Translator::cursorUp;
	commands['<'] = &BF_Translator::cursorDown;
	commands['.'] = &BF_Translator::writeMemory;
	commands[','] = &BF_Translator::readMemory;
	commands['['] = &BF_Translator::loopMemory;
	commands[']'] = &BF_Translator::backFile;
}

BF_Translator::~BF_Translator()
{

}

int BF_Translator::translate(const std::string & _in, const std::string & _out)
{
	try
    {
		this->in.open(_in.data(), std::ios::in);
		this->out.open(_out.data(), std::ios::trunc | std::ios::out);
		if (!this->in.is_open() || !this->out.is_open())
			throw std::exception();
		bf_command command;
		fileHeader();
		while (!this->in.eof()) {
			char c = this->in.get();
			command = commands[c];
			if (command)
				(this->*command)();
			else if (!isspace(c) && c != -1) 
				throw std::exception();
		}
		fileFooter();
		this->out.flush();
		this->in.close();
		this->out.close();
	}
	catch (std::exception & e) {
		this->in.close();
		this->out.close();
		return(-1);
	}
	return(0);
}

void BF_Translator::fileHeader()
{
	out << "#include <stdlib.h>\n"
		<< "#include <string.h>\n"
		<< "#define MEMORY_MAX 60*1024\n\n"
		<< "int main() {\n"
		<< " char memory[MEMORY_MAX];\n"
		<< " unsigned int cursor = 0;\n"
		<< "memset(memory, 0, MEMORY_MAX);\n";
}

void BF_Translator::fileFooter()
{
	out << "}\n";
}

void BF_Translator::memoryUp()
{
	out << "memory[cursor]++;\n";
}

void BF_Translator::memoryDown()
{
	out << "memory[cursor]--;\n";
}

void BF_Translator::cursorUp()
{
	out << "cursor++;\n";
}

void BF_Translator::cursorDown()
{
	out << "cursor -= 1;\n";
}

void BF_Translator::writeMemory()
{
	out << "write(1, & memory[cursor], 1);\n";
}

void BF_Translator::readMemory()
{
	out << "read(0, & memory[cursor], 1);\n";
}

void BF_Translator::loopMemory()
{
	out << "while (memory[cursor]) {\n";
}

void BF_Translator::backFile()
{
	out << "}\n";
}