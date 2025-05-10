#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

#include "../includes/MutantStack.hpp"

#define it typename MutantStack<T>::iterator

template <typename T>
MutantStack<T>::MutantStack() {};

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &other) : std::stack<T>(other) {}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T> &other)
{
    if (this != &other)
        std::stack<T>::operator=(other);
    return (*this);
}

template <typename T>
MutantStack<T>::~MutantStack() {}

template <typename T>
it  MutantStack<T>::begin() { return (this->c.begin()); }

template <typename T>
it  MutantStack<T>::end() { return (this->c.end()); }

#endif