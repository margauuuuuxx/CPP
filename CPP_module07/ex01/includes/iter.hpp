#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>
#include <iostream>

template <typename T>
void    iter(T* arr, size_t size, void(*fct)(T&))
{
    for (size_t i = 0; i < size; i++)
        fct(arr[i]);
}

template <typename T>
void    printElement(T& element)
{
    std::cout << element << std::endl;
}

#endif