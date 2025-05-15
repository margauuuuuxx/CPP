#ifndef PMERGEME_CLASS_HPP
#define PMERGEME_CLASS_HPP

#include <iostream>
#include <stdexcept>
#include <list>
#include <deque>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>

class PmergeMe
{
    private:
        std::list<int>  _list;
        std::deque<int> _deque;
        int compsNbr;
        
        public:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe&    operator=(const PmergeMe &other);
        ~PmergeMe();

        void    parse(int count, char **argv);
        std::list<int>  getList();
        std::deque<int> getDeque();

        template <typename T>
        void    sort(T& container, int recursionLevel);

        template <typename T>
        static bool comparePairs(T it1, T it2);
};

#include "../srcs/PmergeMe.tpp"

#endif