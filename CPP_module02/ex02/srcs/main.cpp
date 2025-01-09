#include "../includes/Fixed.class.hpp"

int main()
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    Fixed c(3.14f);
    Fixed const d(0);

    std::cout << "a value:\t" << a << std::endl;
    std::cout << "a value after pre incrementation:\t" << ++a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << "a value after post incrementation:\t" << a << std::endl;
    std::cout << "b value:\t" << b << std::endl;
    std::cout << "Max fct ouput:\t" << Fixed::max( a, c ) << std::endl;
    std::cout << "Min fct output:\t" << Fixed::min( a, c) << std::endl;
    std::cout << "Cst max fct ouput:\t" << Fixed::maxCst(a, b) << std::endl;
    std::cout << "Cst min fct output:\t" << Fixed::minCst(a, b) << std::endl;
    std::cout << "Null division:\t" << b / d << std::endl;

    return 0;
}