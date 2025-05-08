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

int Span::shortestSpan() const
{
    if (_data.size()< 2)
        throw std::runtime_error("\033[38;5;208mNot enouhg elements to compute span\033[0m");

    std::vector<int> sorted;
    sorted = _data;
    std::sort(sorted.begin(), sorted.end());
    int minSpan;
    minSpan = std::numeric_limits<int>::max();
    for (size_t i = 1; i < sorted.size(); ++i)
    {
        int diff = sorted[i] - sorted[i - 1];
        if (diff < minSpan)
            minSpan = diff;
    }
    return (minSpan);
}

int Span::longestSpan() const
{
    if (_data.size()< 2)
    throw std::runtime_error("\033[38;5;208mNot enouhg elements to compute span\033[0m");

    int minVal = *std::min_element(_data.begin(), _data.end());
    int maxVal = *std::max_element(_data.begin(), _data.end());
    return (maxVal - minVal);
}

int Span::getSize() const { return (_N); }

int Span::getElement(unsigned int i) const
{
    if (i >= _N)
        throw std::runtime_error("\033[38;5;208mCannot find data element because index is out of range\033[0m");
    return (_data[i]);
}