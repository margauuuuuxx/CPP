#include <iostream>

#define BLUE = "\033[34m"

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string& stringREF = str;

    std::cout << "Memory address of the string: " << "\033[34m" << &str << "\033[0m" << std::endl;
    std::cout << "\tMemory address of the string's internal data: " << "\033[34m" << static_cast<const void *>(str.c_str()) << "\033[0m" << std::endl;
    std::cout << "Memory address of stringPTR (stringPTR in itself): " << "\033[34m" << stringPTR << "\033[0m" << std::endl;
    std::cout << "Memory address of stringREF: " << "\033[34m" << &stringREF << "\033[0m" << std::endl;
    std::cout << std::endl;
    std::cout << "----------> SEE 😎 THEY ALL HAVE THE SAME ADDRESS 😳" << std::endl;
    std::cout << std::endl;
    std::cout << "Value of str:  " << str << std::endl;
    std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
    std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;
    std::cout << "\tstringREF in istelf: " << stringREF << std::endl;
}

/*
    ///THEORY RECALL

    - ptr = var that holds the memory address of another var
        dereference = accessing the value that the ptr points to by using *ptr
        reassignable  

    - reference = allias for another variable 
                    provides another name for an existing var 
                    ALWAYS refers to the same object
        cant be null
        not reassignable 
*/