#include <iostream>
#include "array.h"

int main()
{
    std::cout << "Hello World my name is Sophie\n";

    //Templates and container classes:
    Array<int> intArray{ 12 };
    Array<double> doubleArray{ 12 };

    for(int count{ 0 }; count < intArray.getLength(); ++count)
    {
        intArray[count] = count;
        doubleArray[count] = count + 0.5;
    }

    for(int count{ intArray.getLength() - 1 }; count >= 0; --count)
        std::cout << intArray[count] << '\t' << doubleArray[count] << '\n';
    
    // "template classes are truly one of C++’s best and most useful features."

    //Template classes in the standard library:

    //Splitting up template classes:
    //read this all again and try use it...


    return 0;
}