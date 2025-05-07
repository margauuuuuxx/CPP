#include "../includes/Span.class.hpp"

Span::Span(unsigned int N) : _N(N) {}
Span::Span(const Span &other) { *this = other; }
Span&   Span::operator = (const Span &other)
{
    if (this != &other)
    {
        this->_N = other._N;
        this->_data = other._data;
    }
    return (*this);
}
Span::~Span() {}

void    Span::addNumber(int nbr)
{
    if (this->_data.size() == this->_N)
        throw std::runtime_error("\033[38;5;208mMax number of elements atained: cannot add another number\033[0m");
    this->_data.push_back(nbr);
}

template <typename T>
void    Span::addRange(T begin, T end)
{
    size_t  rangeSize;

    rangeSize = std::distance(begin, end);
    if (this->_data.size() + rangeSize > this->_N)
        throw std::runtime_error("\033[38;5;208mMax number of elements atained: cannot add another number\033[0m");
    this->_data.insert(_data.end(), begin, end);
}