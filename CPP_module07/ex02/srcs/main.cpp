#include "../includes/Array.class.hpp"

int main()
{
    std::cout << "***** default constructor test *****" << std::endl;
    Array<int>  a;
    std::cout << "a size = " << a.size() << std::endl;

    std::cout << std::endl;
    std::cout << "***** constructor with size test *****" << std::endl;
    Array<int>  b(5);
    std::cout << "b size = " << b.size() << std::endl;
    for (size_t i = 0; i < b.size(); i++)
        std::cout << "Element at index i = " << i << " :" << b[i] << std::endl;

    std::cout << std::endl;
    std::cout << "***** changing the value of an element *****" << std::endl;
    b[4] = b[4] + 10;
    std::cout << "Changed element = " << b[4] << std::endl;

    std::cout << std::endl;
    std::cout << "***** trying to access an invalid index *****" << std::endl;
    try {
        std::cout << b[6] << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Caught exception : " << e.what() << std::endl;
    }

    return (0);
}