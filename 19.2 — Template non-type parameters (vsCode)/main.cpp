#include <iostream>
#include <cassert>
#include <iterator>



template<typename T, int size>// size is an integral non-type parameter
class StaticArray
{
private:
    // The non-type parameter controls the size of the array
    T m_array[size]{};

public:
    T* getArray();

    T& operator[](int index)
    {
        assert(index >= 0 && "WOWOWOWOWOWOWOW !!!!!");
        return m_array[index];
    }

};

// Showing how a function for a class with a non-type parameter is defined outside of the class
template<typename T, int size>
T* StaticArray<T, size>::getArray()
{
    return m_array;
}


int main()
{
    std::cout << "Hello World my name is Sophie <3\n";

    //Non-type parameters:

    StaticArray<int, 12> intArray; // declare an integer array with room for 12 integers

    for(int i{ 0 }; i < 12; ++i) // Fill it up in order, then print it backwards
        intArray[i] = i;

    for(int i{ 11 }; i >= 0; --i)
        std::cout << intArray[i] << ' ';

    std::cout << '\n';

    // declare a double buffer with room for 4 doubles
    StaticArray<double, 4> doubleArray;

    for(int i{ 0 }; i < 4; ++i)
        doubleArray[i] = 4.4 + 0.1 * i;

    for(int i { 3 }; i >= 0; --i)
        std::cout << doubleArray[i] << ' ';
    
    std::cout << '\n';

 
    return 0;
}