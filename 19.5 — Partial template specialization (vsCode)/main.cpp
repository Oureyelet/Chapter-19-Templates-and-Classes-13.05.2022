#include <iostream>
#include <cstring>

template<typename T, int size> // size is the expression parameter
class StaticArray_Base
{
private:
    // The expression parameter controls the size of the array
    T m_array[size]{};

public:
    T* getArray() { return m_array; }

    T& operator[](int index)
    {
        return m_array[index];
    }

    void member_FCT_Print()
    {
        for(int count{ 0 }; count < size; ++count)
            std::cout << m_array[count];
        std::cout << '\n';
    }

    virtual ~StaticArray_Base() = default;
};

template<typename T, int size>
void print(StaticArray_Base<T, size>& array)
{
    for(int count{ 0 }; count < size; ++count)
        std::cout << array[count] << ' ';
}

// Override print() for fully specialized StaticArray_Base<char, 14>
template<>
void print(StaticArray_Base<char, 14>& array)
{
    for(int count{ 0 }; count < 14; ++count)
        std::cout << array[count];
}

// overload of print() function for partially specialized StaticArray_Base<char, size>
template<int size> // size is still a templated expression parameter
void print(StaticArray_Base<char, size>& array) // we're explicitly defining type char here
{
    for(int count{ 0 }; count < size; ++count)
        std::cout << array[count];
}

template<typename T, int size>
class StaticArray : public StaticArray_Base<T, size>
{
public:
};

template<int size>
class StaticArray<double, size> : public StaticArray_Base<double, size>
{
public:
    void print()
    {
        for(int i{ 0 }; i < size; ++i)
            std::cout << std::scientific << this -> m_array[i];
        std::cout << '\n';
    }

};




int main()
{
    std::cout << "Hello World my name is Sophie\n";

    // declare an int array
    StaticArray_Base<int, 4> int4{};

    int4[0] = 0;
    int4[1] = 1;
    int4[2] = 2;
    int4[3] = 3;

    // Print the array
    print(int4);

    StaticArray_Base<char, 14> char14{};

    std::cout << '\n';

    std::strcpy(char14.getArray(), "Hello World");

    print(char14);

    std::cout << '\n';

    // declare a char array
    StaticArray_Base<char, 12> char12{};

    std::strcpy(char12.getArray(), "Hello, mum!");

    // Print the array
    print(char12);

    //Partial template specialization:

    //Partial template specialization for member functions:

    std::cout << '\n';

    StaticArray<int, 6> intArray{};// declare an integer array with room for 6 integers

    for(int count{ 0 }; count < 6; ++count)// Fill it up in order, then print it
        intArray[count] = count;
    
    intArray.member_FCT_Print();

    std::cout << '\n';

    StaticArray<double, 4> doubleArray{};// declare a double buffer with room for 4 doubles

    for(int i{ 0 }; i < 4; ++i)
        doubleArray[i] = i;
    
    doubleArray.member_FCT_Print();


    //its no printing with std::scientific check why...

    return 0;
}