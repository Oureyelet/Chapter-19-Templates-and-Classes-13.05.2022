#include <iostream>
#include <string>

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

    void print();
};

template<>
void Storage<double>::print()
{
    std::cout << std::scientific << m_value << '\n';
    
}

template<typename T>
class String
{
private:
    T m_value{};

public:
    String(T value)
        : m_value{ value }
    {
    }

    ~String(){}; // need an explicitly defined destructor to specialize   

    void print()
    {
        std::cout << m_value << '\n';
    }
};

template<>
String<char*>::String(char* value)
{
    if(!value)
        return;

    // Figure out how long the string in value is
    int length{ 0 };
    while (value[length] != '\0')
    {
        ++length;
    }
    ++length;// +1 to account for null terminator
    
    // Allocate memory to hold the value string
    m_value = new char[length];

    // Copy the actual value string into the m_value memory we just allocated
    for(int count = 0; count < length; ++count)
    {
        m_value[count] = value[count];
    }
}

template<>
String<char*>::~String()
{
    delete[] m_value;
}

int main()
{
    std::cout << "Hello World my name is Sophie\n";

    // Define some storage units
    Storage<double> iValue{ 5 };
    Storage<double> dValue{ 6.7 };

    // Print out some values
    iValue.print();
    dValue.print();

    //Another example:

    std::string s;  // Dynamically allocate a temporary string

    std::cout << "Enter your name please: ";  // Ask user for their name
    std::cin >> s;

    String<char*> storage(s.data());// Store the name

    storage.print(); // print our name

    s.clear();  // clear the std::string

    storage.print(); // print nothing



    return 0;
}