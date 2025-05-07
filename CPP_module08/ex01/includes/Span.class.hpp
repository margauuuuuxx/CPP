#ifndef SPAN_CLASS_HPP
#define SPAN_CLASS_HPP

#include <vector>
#include <stdexcept>

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
        template <typename T>
        void    addRange(T begin, T end);
        int shortestSpan() const;
        int longestSpan() const;
};

#endif