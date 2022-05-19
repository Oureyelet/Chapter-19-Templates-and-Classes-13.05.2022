#include <iostream>

template<typename T, int size> // size is the expression parameter
class StaticArray
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
};

int main()
{
    std::cout << "Hello World my name is Sophie\n";

    return 0;
}