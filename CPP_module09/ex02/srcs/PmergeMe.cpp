#include "../includes/PmergeMe.class.hpp"

// ***** BASICS *****
PmergeMe::PmergeMe() : compsNbr(0) {}

PmergeMe::PmergeMe(const PmergeMe &other) {*this = other; }

PmergeMe&    PmergeMe:: operator = (const PmergeMe &other)
{
    if (this != &other)
        std::cout << std::endl;
        //implement
    return (*this);
}

PmergeMe::~PmergeMe() {}

// ***** PARSING FCTS ******
void    PmergeMe::parse(int count, char **argv)
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
}

// ***** GETTERS *****
std::list<int>  PmergeMe::getList() { return (this->_list); }
std::deque<int> PmergeMe::getDeque() { return (this->_deque); }