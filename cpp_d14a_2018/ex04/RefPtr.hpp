/*
** EPITECH PROJECT, 2019
** RefPtr.hpp
** File description:
** RefPtr
*/

#ifndef REFPTR_HPP_
	#define REFPTR_HPP_

    #include <cstddef>
    #include "BaseComponent.hpp"

    class RefPtr
    {
        public:
            RefPtr(BaseComponent *);
            RefPtr() : RefPtr(nullptr) {}
            RefPtr(RefPtr const &);
            ~RefPtr();
            RefPtr &operator=(RefPtr const &);
            BaseComponent *get() const;

        private:
            BaseComponent *_rawPtr;
            int *_refCounter;
    };

#endif /* !REFPTR_HPP_ */