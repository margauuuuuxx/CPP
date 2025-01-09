#include "../includes/Fixed.class.hpp"

int main()
{
    Fixed   a;
    Fixed   b( a ); // calling copy constructor 
    Fixed   c;

    c = b; // calling copy assignment operator 

    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;

    return (0);
}