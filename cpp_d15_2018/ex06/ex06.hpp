/*
** EPITECH PROJECT, 2019
** ex06.hpp
** File description:
** @epitech.eu
*/

#ifndef EX06_HPP_
	#define EX06_HPP_

    #include <string>
    #include <sstream>

    template<typename T1, typename T2 = T1>
    class Tuple {
    public:
        T1 a;
        T2 b;

        std::string toString() {
            return std::string("[TUPLE [") + print(a) + "] [" + print(b) + "]]";
        }
    };

    template<typename T>
    std::string print(T) {
        return std::string("???");
    }

    template<>
    std::string print(int a) {
        std::stringstream oss;
        oss << a;
        return std::string("int:") + oss.str();
    }

    template<>
    std::string print(float a) {
        std::stringstream oss;
        oss << a;
        return std::string("float:") + oss.str();
    }

    template<>
    std::string print(std::string a) {
        return std::string("string:\"") + a + "\"";
    }

#endif /* !EX06_HPP_ */
