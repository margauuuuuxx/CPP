#include "../includes/A.class.hpp"
#include "../includes/B.class.hpp"
#include "../includes/C.class.hpp"
#include "../includes/Base.class.hpp"

#include <cstdlib>
#include <ctime>

Base*   generate(void)
{
    int r;

    srand(time(0));
    r = rand() % 3;
    switch (r)
    {
        case 0 : return new A();
        case 1 : return new B();
        case 2 : return new C();
        default : return (NULL);
    }
}
void    identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "Object type : A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Object type : B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Object type : C" << std::endl;
    else 
        std::cout << "Unrecognized object type" << std::endl;
}

void    identify(Base& p)
{
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "Referenced object type : A" << std::endl;
        return;
    }   catch (const std::bad_cast&) {}

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "Referenced object type : B" << std::endl;
        return;
    }   catch (const std::bad_cast&) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "Referenced object type : C" << std::endl;
        return;
    }   catch (const std::bad_cast&) {}

    std::cout << "Unrecognized reference type" << std::endl;
}

int main()
{
    Base* base = generate();
    identify(base);
    identify(*base);
    delete (base);

    std::cout << std::endl;

    base = new A();
    identify(base);
    identify(*base);
    delete(base);

    std::cout << std::endl;

    base = new B();
    identify(base);
    identify(*base);
    delete(base);

    std::cout << std::endl;

    base = new C();
    identify(base);
    identify(*base);
    delete(base);

    return (0);
}