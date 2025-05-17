#include "../includes/PmergeMe.class.hpp"

// ***** SORTING FCTS ******
void    PmergeMe::initTime()
{
    std::cout << "Before: ";
    display(_deque);

    std::clock_t    start;
    std::clock_t    end;

    start = std::clock();
    _list = sort(_list);
    end = std::clock();
    double listT = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;

    start = std::clock();
    _deque = sort(_deque);
    end = std::clock();
    double dequeT = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;

    std::cout << "After: ";
    display(_list);

    std::cout << "Time to sort with a deque container:\t" << dequeT << " of a size:\t" << _deque.size() << std::endl;
    std::cout << "Time to sort with a list container:\t" << listT << " of a size:\t" << _list.size() << std::endl;
}


// ***** BASICS *****
PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(int count, char **argv)
{
    for (int i = 0; i < count; ++i)
    {
        std::stringstream   ss(argv[i]);
        int                 value;

        if (!(ss >> value) || !(ss.eof()) || value < 0)
            throw std::runtime_error("\e[31mError: Parsing of arguments " + std::string(argv[i]) + "..\e[0m");
        this->_deque.push_back(value);
        this->_list.push_back(value);
    }

    initTime();
}

PmergeMe::PmergeMe(const PmergeMe &other) {*this = other; }

PmergeMe&    PmergeMe:: operator = (const PmergeMe &other)
{
    if (this != &other)
    {
        this->_deque = other._deque;
        this->_list = other._list;
    }
    return (*this);
}

PmergeMe::~PmergeMe() {}

// ***** GETTERS *****
std::list<int>  PmergeMe::getList() { return (this->_list); }
std::deque<int> PmergeMe::getDeque() { return (this->_deque); }