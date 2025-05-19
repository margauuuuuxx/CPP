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

template <typename T>
T    sort(const T& container)
{
    if (container.size() <= 1)
        return (container);

    typedef typename T::value_type  valueType;
    typename T::const_iterator      it = container.begin();
    std::vector<valueType>          main;
    std::vector<valueType>          pend;
    
    while (it != container.end())
    {
        valueType   first = *it;
        ++it;
        if (it != container.end())
        {
            valueType   second = *it;
            ++it;
            if (first > second)
                std::swap(first, second);
            pend.push_back(first);
            main.push_back(second);
        }
        else
            main.push_back(first);
    }

    std::sort(main.begin(), main.end());

    std::vector<size_t> insertionOrder  = jacobsthalNbrs(pend.size());
    std::set<size_t> inserted;
    for (size_t i = 0; i < insertionOrder.size(); ++i)
    {
        size_t index    = insertionOrder[i];

        if (index >= pend.size() || inserted.count(index))
            continue;
        inserted.insert(index);

        valueType val   = pend[index];

        typename std::vector<valueType>::iterator   pos;
        pos = std::lower_bound(main.begin(), main.end(), val);
        main.insert(pos, val);
    }

    T result;
    for (size_t i = 0; i < main.size(); ++i)
        result.push_back(main[i]);
    return (result);

    // std::pair<T, T> parts = split(container);
    // T left = sort(parts.first);
    // T right = sort(parts.second);

    // return (merge(left, right));
}

#endif