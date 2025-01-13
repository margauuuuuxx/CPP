#include <iostream>
#include <vector>
#include <limits>

int main()
{
    //STD PREFIX 
    std::cout << "Hello, Wolrd!" << std::endl; // -> outputs to console 
    
    int x;
    std::cin >> x; // -> retrieves input from user and store it

    std::vector<int> numbers = {1, 2, 3, 4}; // for containers (dynamic arrays)

    std::string name = "Margaux"; // -> for strings 

    // DATA TYPES 
    int min = std::numeric_limits<int>::min();
    int max = std::numeric_limits<int>::max();

    //CASTING
    int i = 1;
    double j = static_cast<double>(i);

    class Base {};
    class Derived : public Base{};
    Base* b = new Derived;
    Derived* d = static_cast<Derived*>(b); // NOT SAFE IF b DOESNT POINT TO A DERIVED OBJECT

    void* ptr = &i; //asuming int i
    int* int_ptre = static_cast<int*>(ptr); // converting a void into a specific type 
}


// PASSING BY REFERENCE 
void    modifyValue(int &value) // NO COPIES MADE, MODIFY THE VALUE
{
    value = 42;
}

void dontModifyValue(const int &value) // NO COPIES MADE BUT VALUE NOT MODIFIED 
{
    std::cout << value << std::endl;
}

int main()
{
    int value = 5;
    modifyValue(value);
    std::cout << "Value 1 : " << value << std::endl; // -> will output 42
    return (0);
}


// GOING THROUGH A STR
int main()
{
    std::string str = "Hello world !\n";
    // 1.
    for (size_t i = 0; i < str.length(); i++)
        std::cout << str[i] << std::endl;
    // 2.
    for (char c : str)
        std::cout << c << std::endl;
    // 3.
    for (std::string::iterator it = str.begin(); it != str.end(); it++)
        std::cout << *it << std::endl;
    return (0);
}

/* 
    PTRS TO MEMBER FUNCTIONS
        syntax:
            ReturnType (ClassName::*PointerName) (ParameterTypes) = &ClassName::MemberFunction;
        usage:
            (instance.*PointerName)(args); --> for calling for an object
            (ptrToInstance->*PointerName)(args); --> for a ptr to an object
*/
class MyClass
{
    public:
        void    greet(const std::string& name) {std::cout << "Hello" << name << std::endl;}
        void    bye(const std::string &name) {std::cout << "Byeee" << std::endl;}
};

int main()
{
    MyClass obj;

    //declare a ptr to a member fct
    void    (MyClass::*fctPtr)(const std::string&);

    // assign a member fct to the ptr
    fctPtr = &MyClass::greet;

    // call the fct through the ptr
    (obj.*fctPtr)("Marg");
}