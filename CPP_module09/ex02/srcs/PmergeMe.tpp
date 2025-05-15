#ifndef PMERGEME_TPP
#define PMERGEME_TPP

#include "../includes/PmergeMe.class.hpp"

template <typename T>
bool  comparePairs(T it1, T it2)
{
    compsNbr++;
    return (*it1 < *it2);
}

template <typename T>
void    swapPairs(T it, int recursionLevel)
{
    T   start = next(it, -recursionLevel + 1);
    T   end = next(start, recursionLevel);
    
    while (start != end)
    {
        std::iter_swap(start, next(start, recursionLevel));
        start++;
    } 
}

long    getJacobsthalNbr(long n) { return (round(pow(2, n + 1) + pow(-1, n)) / 3)}

template <typename T>
void    PmergeMe::sort(T& container, int recursionLevel)
{
    typedef typename T::iterator it;

    int pairNbr = container.size() / recursionLevel;
    if (pairNbr < 2)
        return;

    bool    isOdd = pairNbr % 2 == 1;

    it start = container.begin();
    it last = next(container.begin(), recursionLevel * pairNbr);
    it end = next(last, -(isOdd * recursionLevel));

    int jump = 2 * recursionLevel;
    for(it iterator = start; iterator != end; std::advance(iterator, jump))
    {
        it  currentPair = next(iterator, recursionLevel - 1);
        it  nextPair = next(iterator, recursionLevel * 2 - 1);
        if (compareContainers(nextPair, currentPair))
            swapPairs(currentPair, recursionLevel);
    }

    sort(container, recursionLevel * 2);

    std::vector<it> main;
    std::vector<it> pend;

    main.insert(main.end(), next(container.begin(), recursionLevel - 1));
    main.insert(main.end(), next(container.begin(), recursionLevel * 2 -1));

    for (int i = 4; i <= pairNbr; i += 2)
    {
        pend.insert(pend.end(), next(container.begin(), recursionLevel * (i - 1) - 1));
        main.insert(main.end(), next(container.begin(), recursionLevel * i - 1));
    }

    if (isOdd)
        pend.insert(pend.end(), next(end, recursionLevel - 1));
    
    int prevJacob = getJacobsthalNbr(1);
    int inserted = 0;

    for (int i = 2; ; i++)
    {
        int currentJacob = getJacobsthalNbr(i);
        int diff = currentJacob - prevJacob;
        int offset = 0;

        if (diff > static_cast<int>(pend.size()))
            break;
        
        int repetitions = diff;
        typename std::vector<it>::iterator   pendIt = next(pend.begin(), diff, - 1);
        typename std::vector<it>::iterator   boundIt = next(main.begin(), currentJacob + inserted);
        while (repetitions)
        {
            typename std::vector<it>::iterator  idx = std::upper_bound(main.begin(), boundIt, *pendIt, )
        }
    }
}

#endif