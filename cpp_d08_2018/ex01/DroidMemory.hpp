/*
** EPITECH PROJECT, 2019
** droidmemory.hh
** File description:
** @epitech.eu
*/

#ifndef DROIDMEMORY_HH_
    #define DROIDMEMORY_HH_

    #include <string>
    #include <iostream>
    #include <cstdlib>

    class DroidMemory {
        private:
            size_t _fingerPrint;
            size_t _exp;
            static void fusion(DroidMemory &dest, DroidMemory const &memory1, DroidMemory const &memory2);
        public:
            DroidMemory();
            ~DroidMemory();

            size_t getFingerPrint() const;
            size_t getExp() const;

            void setFingerPrint(size_t fingerPrint);
            void setExp(size_t exp);

            void addExp(size_t exp);

            DroidMemory & operator<<(DroidMemory const & memory);
            DroidMemory const & operator>>(DroidMemory & memory) const;
            DroidMemory & operator+=(DroidMemory const & memory);
            DroidMemory & operator+=(size_t exp);
            DroidMemory & operator+(DroidMemory const & memory) const;
            DroidMemory & operator+(size_t exp) const;

            bool operator==(DroidMemory const & memory) const;
            bool operator!=(DroidMemory const & memory) const;
            bool operator<(DroidMemory const & memory) const;
            bool operator<=(DroidMemory const & memory) const;
            bool operator>(DroidMemory const & memory) const;
            bool operator>=(DroidMemory const & memory) const;
            bool operator<(size_t memory) const;
            bool operator<=(size_t memory) const;
            bool operator>(size_t memory) const;
            bool operator>=(size_t memory) const;
    };
    
    std::ostream & operator<<(std::ostream & os, DroidMemory const & memory);

#endif /* !DROIDMEMORY_HH_ */