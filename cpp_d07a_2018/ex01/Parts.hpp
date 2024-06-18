/*
** EPITECH PROJECT, 2019
** Parts.hh
** File description:
** @epitech.eu
*/

#ifndef PARTS_HH_
    #define PARTS_HH_

    #include <string>
    #include <iostream>

    class Arms {
        private:
            std::string _serial;
            bool _functionnal;
        public:
            Arms(std::string serial = "A-01", bool functionnal = true);

            const std::string serial();
            const bool getFunctionnal();
            const void informations();
    };

    class Legs {
        private:
            std::string _serial;
            bool _functionnal;
        public:
            Legs(std::string serial = "L-01", bool functionnal = true);

            const std::string serial();
            const bool getFunctionnal();
            const void informations();
    };

    class Head {
        private:
            std::string _serial;
            bool _functionnal;
        public:
            Head(std::string serial = "H-01", bool functionnal = true);

            const std::string serial();
            const bool getFunctionnal();
            const void informations();
    };

#endif /* !PARTS_HH_ */