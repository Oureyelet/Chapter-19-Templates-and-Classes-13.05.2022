#include <iostream>
#include <cstring>
#include <string>

// Our Storage class for non-pointers
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

    void print() const
    {
        std::cout << m_value << '\n';
    }
};

template<typename T>
class Storage<T*> // this is a partial-specialization of Storage that works with pointer types
{
private:
    T* m_value{};

public:
    Storage(T* value)// for pointer type T
        : m_value{ new T{ *value } }// this copies a single value, not an array
    {
    }

    ~Storage()
    {
        delete m_value;// so we use scalar delete here, not array delete
    }

    void print() const
    {
        std::cout << *m_value << '\n';
    }
};

// Full specialization of constructor for type char*
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

// Full specialization of destructor for type char*
template<>
Storage<char*>::~Storage()
{
    delete[] m_value; 
}

// Full specialization of print function for type char*
// Without this, printing a Storage<char*> would call Storage<T*>::print(), which only prints the first char
template<>
void Storage<char*>::print() const
{
    std::cout << m_value << '\n';
}



int main()
{
    std::cout << "Hello World my name is Sophie\n";

    int a{ 5 };

    int* b{ &a };

    std::cout << "'a' value: " << a << '\n';
    std::cout << "'a' addres: " << &a << '\n';
    std::cout << "'b' addres: " << b << '\n';
    std::cout << "'b' value: " << *b << '\n';
    std::cout << "'b pointer' addres: " << &b << '\n';

    // Declare a non-pointer Storage to show it works
    Storage<int> myint{ 5 };
    myint.print();

    // Declare a pointer Storage to show it works
    int x{ 77 };
    Storage<int*> myintptr{ &x };

    // Let's show that myintptr is separate from x.
	// If we change x, myintptr should not change
    x = 122;
    myintptr.print();

    // Dynamically allocate a temporary string
    char* name{ new char[5]{ 'A' } };

    // Store the name
    Storage<char*> myName{ name };

    // Delete the temporary string
    delete[] name;

    // Print out our name to prove we made a copy
    myName.print();

    return 0;
}