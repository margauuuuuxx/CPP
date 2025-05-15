#include "../includes/PmergeMe.class.hpp"

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        std::cerr << "\e[31mError: Wrong number of arguments ..\e[0m" << std::endl;
        return (1);
    }

    PmergeMe pm;

    try {
        pm.parse(argc - 1, argv + 1);

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    // std::list<int>  l = pm.getList();
    // std::deque<int> d = pm.getDeque();
    // for (std::deque<int>::iterator it = d.begin(); it != d.end(); ++it)
    //     std::cout << "Deque:\t" << *it << std::endl;; 
    // for(std::list<int>::iterator it = l.begin(); it != l.end(); ++it)
    //     std::cout << "List:\t" << *it << std::endl;

    return (0);
}