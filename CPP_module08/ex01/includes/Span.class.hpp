#ifndef SPAN_CLASS_HPP
#define SPAN_CLASS_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>
#include <limits>

class   Span
{
    private:
        unsigned int        _N;
        std::vector<int>    _data;

    public:
        Span(unsigned int N);
        Span(const Span &other);
        Span& operator=(const Span &other);
        ~Span();

        void    addNumber(int nbr);
        int shortestSpan() const;
        int longestSpan() const;
        int getSize() const;
        int getElement(unsigned int i) const;

        template <typename T>
        void    addRange(T begin, T end)
        {
            size_t  rangeSize;

            rangeSize = std::distance(begin, end);
            if (this->_data.size() + rangeSize > this->_N)
                throw std::runtime_error("\033[38;5;208mMax number of elements atained: cannot add another number\033[0m");
            this->_data.insert(_data.end(), begin, end);
        }
};

#endif