#include "easyfind.tpp"

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <cmath>
#include <iomanip>

int main()
{
    std::cout << "***** TEST WITH VECTOR *****" << std::endl;
    std::vector<int> v;
    for (int i = 0; i < 5; i++)
    {
        v.push_back(i);
        std::cout << "Element nbr i = " << i << " of value " << v[i] << std::endl;
    }
    std::vector<int>::iterator it = easyfind(v, 3);
    std::cout << "Found: " << *it << std::endl;

    std::cout << std::endl;
    std::cout << "***** TEST WITH LIST *****" << std::endl;
    std::list<float> l;
    for (int i = 0; i < 6; i++)
    {
        float pi_value = M_PI;
        l.push_back(pi_value);
    }
    std::list<float>::iterator itl;
    int i = 0;
    for (itl = l.begin(); itl != l.end(); ++itl)
    {
        std::cout << "Element nbr i = " << i << " of value ";
        std::cout << std::fixed << std::setprecision(i + 1) << *itl << std::endl;
        i++;
    }
    // std::list<float>::iterator itlf = easyfind(l, 5);
    // std::cout << "Found: " << *itlf << std::endl;

    std::cout << std::endl;
    std::cout << "***** TEST WITH SET *****" << std::endl;
    std::set<std::string> s;
    std::string prefixes[] = {"Lil ", "Big ", "Dippin ", "Ice ", "West "};
    std::string sufixes[] = {"Jesus", "Bastard", "Fly", "Boss", "Dog"};
    for (int i = 0; i < 3; ++i)
        s.insert(prefixes[i] + sufixes[4 - i]);
    i = 0;
    std::set<std::string>::iterator its;
    for (its = s.begin(); its != s.end(); ++its)
    {
        std::cout << "Element nbr i = " << i << " of value " << *its << std::endl;
        i++;
    }

    return (0);
}