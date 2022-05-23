#include <iostream>
#include <string>

template<typename T>
class Pair1
{
private:
    T m_first{};
    T m_second{};

public:
    Pair1(const T& v1, const T& v2)
        : m_first{ v1 }, m_second{ v2 }
    {
    }

    const T& first() const { return m_first; } 
    const T& second() const { return m_second; }
};

template<typename T, typename S>
class Pair
{
protected:
    T m_first{};
    S m_second{};

public:
    Pair(const T& v1, const S& v2)
        : m_first{ v1 }, m_second{ v2 }
    {
    }

    const T& first() const { return m_first; }
    const S& second() const { return m_second; }
};

template<typename T>
class StringValuePair: public Pair<std::string, T>
{
public:
    StringValuePair(const std::string& v1, const T& v2)
        : Pair<std::string, T>{ v1, v2 }
    {
    }
};

int main()
{     
    std::cout << "Trwaj przy Panu a on Cie potrzyma w kazdym momencie.\n";

    //Quiz time:
    /*
    It’s sometimes useful to define data that travels in pairs. Write a templated class named Pair1 that allows the user to 
    define one template type that is used for both values in the pair. The following function should work:
    */

    Pair1<int> p1 { 5, 8 };
	std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

	const Pair1<double> p2 { 2.3, 4.5 };
	std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

    /*
    Write a Pair class that allows you to specify separate types for each of the two values in the pair.
    Note: We’re naming this class differently from the previous one because C++ does not currently allow you to “overload” 
    classes that differ only in the number or type of template parameters.
    The following program should work:
    */
    Pair<int, double> p3{ 5, 6.7 };
    std::cout << "Pair: " << p3.first() << ' ' << p3.second() << '\n';

    Pair<double, int> p4{ 2.3, 4 };
    std::cout << "Pair: " << p4.first() << ' ' << p4.second() << '\n'; 

    /*
    A string-value pair is a special type of pair where the first value is always a string type, 
    and the second value can be any type. Write a template class named StringValuePair that inherits 
    from a partially specialized Pair class (using std::string as the first type, and allowing the user to 
    specify the second type).
    The following program should run:
    */
    StringValuePair<int> svp { "Hello", 5 };
	std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';


    // BINGO ! ;D 


    return 0;
}