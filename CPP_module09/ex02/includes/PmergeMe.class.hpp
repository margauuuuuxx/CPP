#ifndef PMERGEME_CLASS_HPP
#define PMERGEME_CLASS_HPP

#include <iostream>
#include <stdexcept>
#include <list>
#include <deque>

class PmergeMe
{
    private:
        std::list<int>  _list;
        std::deque<int> _deque;
        PmergeMe();

    public:
        PmergeMe(std::string data);
        PmergeMe(const PmergeMe &other);
        PmergeMe&    operator=(const PmergeMe &other);
        ~PmergeMe();
};

#endif