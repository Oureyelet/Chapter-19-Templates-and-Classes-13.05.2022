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

template<typename T>
void Storage<T>::print()
{
    std::cout << std::scientific << m_value << '\n';
    
}

int main()
{
    std::cout << "Hello World my name is Sophie\n";

    // Define some storage units
    Storage<int> iValue{ 5 };
    Storage<double> dValue{ 6.7 };

    // Print out some values
    iValue.print();
    dValue.print();

    //Another example:

    std::string s;  // Dynamically allocate a temporary string

    std::cout << "Enter your name please: ";  // Ask user for their name
    std::cin >> s;

    Storage<char*> storage(s.data());// Store the name

    storage.print(); // print our name

    s.clear();  // clear the std::string

    storage.print(); // print nothing

    //"As it turns out, instead of printing the name, the second st..." try understand what thats all mean ?!@#?!@#!@# 


    return 0;
}