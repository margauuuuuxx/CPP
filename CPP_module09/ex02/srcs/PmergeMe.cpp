#include "../includes/PmergeMe.class.hpp"

// // ***** UTILS *****
// template <typename T>
// void    display(const T& container)
// {
//     typename T::const_iterator  it;
//     for (it = container.begin(); it != container.end(); ++it)
//         std::cout << *it << " ";
//     std::cout << std::endl;
// }

// // ***** SORTING FCTS *****
// template <typename T>
// static T    merge(const T& left, const T& right)
// {
//     T   result;
//     typename T::const_iterator  it1 = left.begin();
//     typename T::const_iterator  it2 = right.begin();

//     while (it1 != left.end() && it2 != right.end())
//     {
//         if (*it1 < *it2)
//             result.push_back(*it1++);
//         else
//             result.push_back(*it2++);
//     }

//     result.insert(result.end(), it1, left.end());
//     result.insert(result.end(), it2, right.end());

//     return (result);
// }

// template <typename T>
// static std::pair<T, T>  split(const T& container)
// {
//     T   left;
//     T   right;
//     typename T::const_iterator  it = container.begin();

//     std::advance(it, container.size() / 2);
//     left.assign(container.begin(), it);
//     right.assign(it, container.end());

//     return (std::make_pair(left, right));
// }

// template <typename T>
// T    sort(const T& container)
// {
//     if (container.size() <= 1)
//         return (container);
//     std::pair<T, T> parts = split(container);
//     T left = sort(parts.first);
//     T right = sort(parts.second);

//     return (merge(left, right));
// }

// ***** SORTING FCTS ******
void    PmergeMe::initTime()
{
    std::cout << "Before: ";
    display(_deque);

    std::clock_t    start;
    std::clock_t    end;

    start = std::clock();
    std::list<int> resList = sort(_list);
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