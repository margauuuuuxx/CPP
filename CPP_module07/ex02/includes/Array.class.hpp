#ifndef ARRAY_CLASS_HPP
#define ARRAY_CLASS_HPP

#include <cstddef>
#include <iostream>

template <typename T>
class Array
{
    private:
        T       *array;
        size_t  _size;

    public: 
        Array();
        Array(unsigned int n);
        Array(Array<T> const & other);
        Array& operator=(Array <T> const & other);
        ~Array();

        T   &operator[](size_t index);
        size_t  size() const;
}   ;

#include "../srcs/Array.tpp"

#endif 