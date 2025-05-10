#include "../includes/MutantStack.hpp"

#include <iostream>

int main()
{
    // std::cout << "***** ITERATION TEST WITH A SIMPLE STACK *****" << std::endl;
    // std::stack<int> s;
    // for (int i = 0; i < 10; i++)
    //     s.push(i);
    // std::stack<int>::iterator it;

    std::cout << std::endl;
    std::cout << "***** ITERATION TEST WITH MUTANT STACK *****" << std::endl;
    MutantStack<int>    MS;
    for (int i = 0; i < 10; i++)
        MS.push(i);
    for (MutantStack<int>::iterator its = MS.begin(); its != MS.end(); ++its)
        std::cout << *its << std::endl;

    std::cout << std::endl;
    std::cout << "***** TEST WITH STRINGS STACK *****" << std::endl;
    MutantStack<char>    mString;
    for (int i = 0; i < 10; i++)
    {
        char    letter = 'a' + i;
        mString.push(letter);
    }
    for (MutantStack<char>::iterator its2 = mString.begin(); its2 != mString.end(); ++its2)
        std::cout << *its2 << std::endl;
    std::cout << "Stack size = " << mString.size() << std::endl;
    mString.pop();
    mString.pop();
    mString.pop();
    for (MutantStack<char>::iterator its2 = mString.begin(); its2 != mString.end(); ++its2)
    std::cout << *its2 << std::endl;
    std::cout << "Stack size = " << mString.size() << std::endl;

    return (0);
}