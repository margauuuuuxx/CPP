#include "../includes/whatever.hpp"

/*
    template <typename A, typename B, ..>
    --> template = to declare a template (duh)
    --> typename (== class) = template parameters : types that'll be provided when an instance is created 
*/

int main()
{
    std::cout << "***** tests with ints *****" << std::endl;
    int a = 5;
    int b = -2;
    std::cout << "Swap:" << std::endl;
    std::cout << "Before swap:\ta = " << a << "\tb =" << b << std::endl;
    swap(a, b);
    std::cout << "After swap:\ta = " << a << "\tb = " << b << std::endl;
    std::cout << "Min = " << min(a, b) << std::endl;
    std::cout << "Max = " << max(a, b) << std::endl;

    std::cout << std::endl;
    std::cout << "***** tests with floats *****" << std::endl;
    float c = 3.56;
    float d = -0.99;
    std::cout << "Swap:" << std::endl;
    std::cout << "Before swap:\ta = " << c << "\tb =" << d << std::endl;
    swap(c, d);
    std::cout << "After swap:\ta = " << c << "\tb = " << d << std::endl;
    std::cout << "Min = " << min(c, d) << std::endl;
    std::cout << "Max = " << max(c, d) << std::endl;

    std::cout << std::endl;
    std::cout << "***** tests with strs *****" << std::endl;
    std::string e = "Hello ";
    std::string f = "World !";
    std::cout << "Swap:" << std::endl;
    std::cout << "Before swap:\ta = " << e << "\tb =" << f << std::endl;
    swap(e, f);
    std::cout << "After swap:\ta = " << e << "\tb = " << f << std::endl;
    std::cout << "Min = " << ::min(e, f) << std::endl; // use of :: to refer to our own fcts
    std::cout << "Max = " << ::max(e, f) << std::endl;

    return (0);
}