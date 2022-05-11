#include "whitespace.h"

int main()
{
    std::string stringExample = "     sample string   "; 
    print(whitespaces(stringExample));

    std::vector<char> vectorExample = {' ', ' ', ' ', ' ', ' ', 's', 'a', 'm', 'p', 'l', 'e', ' ', 's', 't', 'r', 'i', 'n', 'g', ' ', ' ', ' '};
    print(whitespaces(vectorExample));

    std::list<char> listExample = {' ', ' ', ' ', ' ', ' ', 's', 'a', 'm', 'p', 'l', 'e', ' ', 's', 't', 'r', 'i', 'n', 'g', ' ', ' ', ' '};
    print(whitespaces(listExample));

}