#include <iostream>

template<typename T>
class Storage8
{
private:
    T m_array[8];

public:
    void set(int index, const T& value)
    {
        m_array[index] = value;
    }

    const T& get(int index) const
    {
        return m_array[index];
    }
    
    T& operator[](int index)
    {
        return m_array[index];
    }
};

template<>// the following is a template class with no templated parameters
class Storage8<bool>// we're specializing Storage8 for bool
{
// What follows is just standard class implementation details
private:
    unsigned char m_data{};

public:
    void set(int index, bool value)
    {
        // Figure out which bit we're setting/unsetting
        // This will put a 1 in the bit we're interested in turning on/off
        auto mask{ 1 << index };

        if(value) // If we're setting a bit 
            m_data |= mask; // Use bitwise-or to turn that bit on
        else // if we're turning a bit off
            m_data &= ~mask; // bitwise-and the inverse mask to turn that bit off
    }

    bool get(int index)
    {
        // Figure out which bit we're getting
        auto mask{ 1 << index };
        // bitwise-and to get the value of the bit we're interested in
        // Then implicit cast to boolean
        return (m_data & mask);
    }
};

int main()
{
    // Define a Storage8 for integers
    Storage8<int> intStorage;

    for(int count{ 0 }; count < 8; ++count)
        intStorage.set(count, count);

    for(int count{ 0 }; count < 8; ++count)
    {
        std::cout << intStorage.get(count) << '\n';
    }

    // Define a Storage8 for bool
    Storage8<bool> boolStorage;

    for(int count{ 0 }; count < 8; ++count)
        boolStorage.set(count, count & 5); // if count == 5 print fails... you can change 5 for any number and moved 'false' wherever you want

    std::cout << std::boolalpha;

    for(int count{ 0 }; count < 8; ++count)
        std::cout << boolStorage.get(count) << '\n';

    //Class template specialization:


    return 0;
}