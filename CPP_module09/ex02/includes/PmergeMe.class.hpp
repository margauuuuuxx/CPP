#ifndef PMERGEME_CLASS_HPP
#define PMERGEME_CLASS_HPP

#include <iostream>
#include <stdexcept>
#include <list>
#include <deque>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <cmath>
#include <ctime>
#include <algorithm>

class PmergeMe
{
    private:
        std::list<int>  _list;
        std::deque<int> _deque;

        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe&    operator=(const PmergeMe &other);

        void    initTime();
        
    public:
        PmergeMe(int count, char **argv);
        ~PmergeMe();

        std::list<int>  getList();
        std::deque<int> getDeque();

    };
    
template <typename T>
T   sort(const T& container);

std::vector<size_t>  jacobsthalNbrs(size_t n);

#include "../srcs/PmergeMe.tpp"

#endif