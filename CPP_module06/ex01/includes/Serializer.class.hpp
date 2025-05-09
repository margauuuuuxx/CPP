#ifndef SERIALIZER_CLASS_HPP
#define SERIALIZER_CLASS_HPP

#include <iostream>
#include <stdint.h>

// a class has DEFAULT PUBLIC ACCESS 
struct Data
{
    int         value;
    std::string text;
};

class Serializer
{
    private:
        Serializer();
        Serializer(const Serializer &other);
        Serializer& operator=(const Serializer &other);
        ~Serializer();

    public:
        static uintptr_t    serialize(Data* ptr);
        static Data*    deserialize(uintptr_t raw);
};

#endif 