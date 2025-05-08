#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

class MutantStack
{
    private:
        std::stack<int> _stack;

    public:
        MutantStack();
        MutantStack(const MutantStack &other);
        MutantStack& operator=(const MutantStack &other);
        ~MutantStack();

        

};

#endif