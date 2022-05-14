#include <iostream>
#include "intArray.h"

int main()
{
    IntArray array{ 7 };

    std::cout << "Enter 7 numbers: \n";
    
    for(int i{ 0 }; i < array.getLength(); ++i)
    {
        std::cin >> array[i];
    }
    std::cout << '\n';
    std::cout << "Here is your input:\n";


    for(int i{ 0 }; i < array.getLength(); ++i)
    {
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;

    

    return 0;
}