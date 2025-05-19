#include "../includes/PmergeMe.class.hpp"

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        std::cerr << "\e[31mError: Wrong number of arguments ..\e[0m" << std::endl;
        return (1);
    }

    try {
        PmergeMe pm(argc - 1, argv + 1);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return (0);
}

/*
    Why is it faster with a list ?
        List                |       Deque
    doubly linked list      | dynamic array of chunks
    --> slow random access  | --> fast random access (O(1))
    (o(n))                  |
    Insertion/removal fast  | Insertion/removal fast at ends
    at any position (O(1))  | slow in the middle (O(n))
*/