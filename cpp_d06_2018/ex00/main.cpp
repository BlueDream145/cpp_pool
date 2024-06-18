/*
** EPITECH PROJECT, 2019
** main.cpp
** File description:
** @epitech.eu
*/

#include <fstream>
#include <string>
#include <iostream>

static int check(int ac)
{
    const char *usage = "my_cat: Usage: ./my_cat file [...]";

    if (ac >= 2)
        return(1);
    std::cerr << usage << std::endl;
    return(0);
}

int main(int ac, char **as)
{
    const char *no_found = "my_cat: ";
    const char *no_found_1 = ": No such file or directory";
    char c;

    if (check(ac))
        for (int i = 1; i < ac; i++) {
            std::ifstream file(as[i]);
            if (!file.is_open())
                std::cerr << no_found << as[i] << no_found_1 << std::endl;
            else {
                c = file.get();
                while (file.good()) {
                    std::cout << c;
                    c = file.get();
                }
                file.close();
            }
        }
    return(0);
}