/*
** EPITECH PROJECT, 2019
** KreogCom.hh
** File description:
** @epitech.eu
*/

#ifndef KREOGCOM_HH_
    #define KREOGCOM_HH_

    #include <string>
    #include <iostream>

    class KreogCom {
        public:
            KreogCom(int, int, int);
            ~KreogCom();
            void addCom(int, int, int);
            KreogCom *getCom();
            void removeCom();
            const void ping();
            const void locateSquad();
        private:
            int m_serial;
            int _x;
            int _y;
            KreogCom *_next;
    };

#endif /* !KREOGCOM_HH_ */