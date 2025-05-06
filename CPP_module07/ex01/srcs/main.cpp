#include "../includes/iter.hpp"

int main()
{
    std::cout << "***** array of ints *****" << std::endl;
    int a[5] = {0, 1, 2, 3, 4};
    iter(a, 5, printElement);

    std::cout << std::endl;
    std::cout << "***** array of floats *****" << std::endl;
    float b[3] = {-0.99, 3.14, 0.0004};
    iter(b, 3, printElement);

    std::cout << std::endl;
    std::cout << "***** array of strings *****" << std::endl;
    std::string c[4] = {"Hello ", ",", " World ", "!"};
    iter(c, 4, printElement);

    return (0);
}