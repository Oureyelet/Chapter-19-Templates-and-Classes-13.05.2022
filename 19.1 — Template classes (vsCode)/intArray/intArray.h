#ifndef INTARRAY_H
#define INTARRAY_H

#include <cassert>

class IntArray
{
private:
    int m_length{};
    int* m_data{};

public:
    IntArray(int length)
    {
        assert(length > 0); // if length will be less then 0 then stop program.
        m_data = new int[length]{};
        m_length = length;
    }

    // We don't want to allow copies of IntArray to be created.
    IntArray(const IntArray&) = delete;
    IntArray& operator=(const IntArray&) = delete;

    ~IntArray()
    {
        delete[] m_data;
    }

    void erase()
    {
        delete[] m_data;

        // We need to make sure we set m_data to 0 here, otherwise it will
        // be left pointing at deallocated memory!
        m_data = nullptr;
        m_length = 0;
    }

    int& operator[](int index)
    {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }

    int getLength() const;
    void getInfo() const;
};

int IntArray::getLength() const
{
    return m_length;
}

void IntArray::getInfo() const
{
    std::cout << "Here is IntArray class\n";
}

#endif // end of INTARRAY_H