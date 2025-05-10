#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

/*
    stack is a CONTAINER ADAPTER meaning that it isnt a container itself
    but it wraps another container (deque<T> by default) and manages access to it
    (i.e by making it non-iterable by default).
    --> This underlying container is stored in a protected member named c 
*/

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack();
        MutantStack(const MutantStack<T> &other);
        MutantStack<T>& operator=(const MutantStack<T> &other);
        ~MutantStack();

    typedef typename    std::stack<T>::container_type::iterator iterator;
    iterator begin();
    iterator end();
};

#include "../srcs/MutantStack.tpp"

#endif