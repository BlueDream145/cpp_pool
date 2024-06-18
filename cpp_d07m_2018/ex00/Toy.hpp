/*
** EPITECH PROJECT, 2019
** Toy.hpp
** File description:
** @epitech.eu
*/

#ifndef TOY_HPP_
	#define TOY_HPP_

    #include <string>

    #include "Picture.hpp"

    class Toy {
        public:

            enum ToyType {
                BASIC_TOY,
                ALIEN,
                BUZZ,
                WOODY
            };

            class Error {
                public:

                    enum ErrorType {
                        UNKNOWN,
                        PICTURE,
                        SPEAK
                    };

                public:
                    ErrorType type;

                    Error();
                    void setType(ErrorType type);
                    std::string what() const;
                    std::string where() const;
            };
            
            Toy();
            Toy(ToyType type, std::string const & name, std::string const & ascii);
            Toy(Toy const & toy);
            virtual ~Toy();

            int getType() const;
            std::string const & getName() const;
            std::string const & getAscii() const;

            void setName(std::string const & name);
            bool setAscii(std::string const & ascii);

            virtual bool speak(std::string const message);
            virtual bool speak_es(std::string const message);

            Toy::Error const & getLastError() const;

            Toy & operator=(Toy const & toy);
            Toy & operator<<(std::string const & ascii);

        protected:
            ToyType type;
            std::string name;
            Picture picture;
            Error error;
    };

std::ostream & operator<<(std::ostream & os, Toy const & toy);

#endif /* !TOY_HPP_ */