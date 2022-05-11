#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <list>

template<typename T>
void print(const T& printable)
{
    for (const char& element : printable)
        std::cout << element;
    std::cout << std::endl;
}

template<typename T>
T whitespaces(const T& text)
{
    T out;

    typename T::const_iterator start = text.begin();
    while (*start == ' ')
        start++;
    
    typename T::const_iterator stop = text.end();
    while (*stop == ' ')
        stop--;    

    for (typename T::const_iterator it = start; it != stop; it++)
    {
        out.push_back(*it);
    }

    return out;
}