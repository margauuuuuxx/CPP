#include "../includes/Span.class.hpp"

#include <iostream>
#include <list>
#include <deque>
#include <set>

int main()
{
    std::cout << "***** TEST ADDING THE ELEMENTS 1 BY 1 *****" << std::endl;
    Span S(10);
    std::cout << "S size = " << S.getSize() << std::endl;
    std::cout << "Printing elements ..." << std::endl;
    for (int i = 0; i < S.getSize(); ++i)
    {
        S.addNumber(i * 10);
        std::cout << "Element at position i = " << i << " of value " << S.getElement(i) << std::endl;
    }
    std::cout << "Shortest span = " << S.shortestSpan() << std::endl;
    std::cout << "Longest span = " << S.longestSpan() << std::endl;

    std::cout << std::endl;
    std::cout << "***** TEST ADDING A RANGE *****" << std::endl;
    
    std::cout << "\t values of the list" << std::endl;
    std::list<float> l;
    for (int i = 0; i < 10000; ++i)
        l.push_back(i);
    Span S2(10100);
    S2.addRange(l.begin(), l.end());
    for (int i = 950; i < 960; ++i)
        std::cout << "Element at position i = " << i << " of value " << S2.getElement(i) << std::endl;
    
    std::cout << "\t values of the deque" << std::endl;
    std::deque<int> d;
    for (int i = 0; i < 50; ++i)
        d.push_back(i * 3);
    S2.addRange(d.begin(), d.end());
    for (int i = 10000; i < 10010; ++i)
        std::cout << "Element at position i = " << i << " of value " << S2.getElement(i) << std::endl;

    std::cout << "\t values of the multiset" << std::endl;
    std::multiset<int> m;
    for (int i = 0; i < 50; ++i)
        m.insert(222);
    S2.addRange(m.begin(), m.end());
    for (int i = 10090; i < 10100; ++i)
        std::cout << "Element at position i = " << i << " of value " << S2.getElement(i) << std::endl;

    std::cout << std::endl;
    std::cout << "***** TEST TO GO ABOVE SIZE *****" << std::endl;
    try{
        S2.addNumber(888);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return (0);
}