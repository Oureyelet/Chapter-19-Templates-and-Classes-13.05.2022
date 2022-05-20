#include <iostream>

template<typename T>
class Storage
{
private:
    T m_value{};

public:
    Storage(T value)
        : m_value{ value }
    {
    }

    ~Storage()
    {
    }

    void print()
    {
        std::cout << m_value << '\n';
    }
};

template<>
Storage<char*>::Storage(char* value)
{
    // Figure out how long the string in value is
    int length{ 0 };

    while(value[length] != '\0')
        ++length;
    ++length;// +1 to account for null terminator

    // Allocate memory to hold the value string
    m_value = new char[length];

    // Copy the actual value string into the m_value memory we just allocated
    for(int count = 0; count < length; ++count)
        m_value[count] = value[count];   
}

template<>
Storage<char*>::~Storage()
{
    delete[] m_value; 
}

int main()
{
    std::cout << "Hello World my name is Sophie\n";

    /*
    While that worked great for Storage<char*>, what about other pointer types (such as int*)? 
    It’s fairly easy to see that if T is any pointer type, then we run i...
    */

    return 0;
}