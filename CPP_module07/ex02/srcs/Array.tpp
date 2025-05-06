#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "../includes/Array.class.hpp"

template <typename T>
Array<T>::Array() : array(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : array(NULL), _size(n) { this->array = new T[this->_size](); }

template <typename T>
Array<T>::Array(Array const &other) : array(NULL), _size(0) { *this = other; }

template <typename T>
Array<T>& Array<T>::operator = (Array const &other)
{
    if (this != &other)
    {
        if (this->array)
            delete[] this->array;
        this->_size = other._size;
        this->array = new T[this->_size];
        for (size_t i = 0; i < this->_size; ++i)
            this->array[i] = other.array[i];
    }
    return (*this);
}

template <typename T>
Array<T>::~Array()
{
    if (this->array)
        delete[] this->array;
}

template <typename T>
T   &Array<T>::operator[](size_t index)
{
    if (index >= this->_size)
        throw std::out_of_range("Index out of range");
    return (this->array[index]);
}

template <typename T>
size_t  Array<T>::size() const { return (_size); }

#endif 