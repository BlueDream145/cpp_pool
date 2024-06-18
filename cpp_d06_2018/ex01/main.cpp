/*
** EPITECH PROJECT, 2019
** main.cpp
** File description:
** @epitech.eu
*/

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <algorithm>

static const char *celsius = "Celsius";
static const char *fahrenheit = "Fahrenheit";
static const char *text;

int main(int ac, char **as)
{
    std::string str;
    std::string tmp;
    std::stringstream stream;
    float var = 5.0 / 9.0;
    float value;

    getline(std::cin, str);
    stream << str;
    stream >> value;
    stream >> tmp;
    std::transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
    if (tmp == "celsius") {
        var = value / var + 32;
        text = fahrenheit;
    } else if (tmp == "fahrenheit") {
        var *= (value - 32);
        text = celsius;
    }
    std::cout << std::setw(16) << std::fixed <<
    std::setprecision(3) << var << std::setw(16) << text << std::endl;
}
