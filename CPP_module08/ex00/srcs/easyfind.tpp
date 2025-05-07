#ifndef EASYFIND_TPP
#define EASYFIND_TPP

#include "../includes/easyfind.hpp"

#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator    easyfind(T& container, int value)
{
    typename T::iterator it;

    it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw std::runtime_error("\033[38;5;208mNo value match\033[0m");
    return (it);
}

#endif