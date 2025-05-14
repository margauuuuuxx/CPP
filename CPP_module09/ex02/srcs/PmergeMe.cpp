#include "../includes/PmergeMe.class.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(std::string data)
{
    
}

PmergeMe::PmergeMe(const PmergeMe &other) {*this = other; }

PmergeMe&    PmergeMe:: operator = (const PmergeMe &other)
{
    if (this != &other)
        //implement
    return (*this);
}

PmergeMe::~PmergeMe() {}

