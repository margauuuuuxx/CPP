#ifndef EASYFIND_HPP
#define EASYFIND_HPP

template <typename T>
typename T::iterator    easyfind(T& container, int value);

/*
    returns an iterator pointing to the 1st occurence 
    passing container by ref :
        - to avoid having to copy the whole container
        - otherwise the iterator will point to an element of the copy which doesnt make sense

*/

#endif