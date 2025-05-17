#ifndef PMERGEME_TPP
#define PMERGEME_TPP

#include "../includes/PmergeMe.class.hpp"

// ***** UTILS *****
template <typename T>
void    display(const T& container)
{
    typename T::const_iterator  it;
    for (it = container.begin(); it != container.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

// ***** SORTING FCTS *****
template <typename T>
static T    merge(const T& left, const T& right)
{
    T   result;
    typename T::const_iterator  it1 = left.begin();
    typename T::const_iterator  it2 = right.begin();

    while (it1 != left.end() && it2 != right.end())
    {
        if (*it1 < *it2)
            result.push_back(*it1++);
        else
            result.push_back(*it2++);
    }

    result.insert(result.end(), it1, left.end());
    result.insert(result.end(), it2, right.end());

    return (result);
}

template <typename T>
static std::pair<T, T>  split(const T& container)
{
    T   left;
    T   right;
    typename T::const_iterator  it = container.begin();

    std::advance(it, container.size() / 2);
    left.assign(container.begin(), it);
    right.assign(it, container.end());

    return (std::make_pair(left, right));
}

template <typename T>
T    sort(const T& container)
{
    if (container.size() <= 1)
        return (container);
    std::pair<T, T> parts = split(container);
    T left = sort(parts.first);
    T right = sort(parts.second);

    return (merge(left, right));
}

#endif