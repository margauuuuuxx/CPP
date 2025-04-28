#include "../includes/Serializer.class.hpp"

/*
    Goal is to interpret a ptr as number and conversly
    the uintptr_t var type is made for this: its large enough to hold any otr value without bits loss
    uintptr_t = the memory address as a number 
*/

int main()
{
    Data    data;
    data.value = 42;
    data.text = "Hello, world!";

    std::cout << "Original data address: " << &data << std::endl;

    uintptr_t   serialized = Serializer::serialize(&data);
    Data*   deserialized = Serializer::deserialize(serialized);

    std::cout << "Deserialized data address: " << deserialized << std::endl;

    if (deserialized == &data)
        std::cout << "Pointers match !!" << std::endl;
    else 
        std::cout << "Pointers don't match ... ://" << std::endl;

    std::cout << "Deserialized content:\n\tnumber = " << deserialized->value << "\n\ttext = " << deserialized->text << std::endl;

    return (0);
}