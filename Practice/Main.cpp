#include <iostream>
#include "Queue.h"
#include "QueueExample.h"

/*
    Templates can be used to make "generic" functions or classes
    for an example of a "generic class" see Queue.h, as well as 
    for more use cases on Template, and Linked List

    to define a function or class as a template, you must put above or on the left
    "template<typename T> or template<typename T, ..." for as many params as you want
    

    T can be anything you can say L or Type, but generally it is a single letter,
    using templates allows for greater reusablility. They are generally also using in conjunction
    with auto, as auto allows the compiler to pick the return or variable type.
    
    Documentation: https://learn.microsoft.com/en-us/cpp/cpp/templates-cpp?view=msvc-170
    Cool video: https://www.youtube.com/watch?v=spZd2rNtze8&list=PLZPZq0r_RZOMHoXIcxze_lP97j2Ase2on&index=52
    
    when using a template class do not forget to define the type within the angle brackets'<T>'

    for example when using the Queue class:
    Queue<int> myQueue; this tells the compiler this is a queue of ints

    int a template class, not every function needs to be a template function
    
*/
template<typename T, typename U>
auto max(T x, U y)
{
    return (x > y) ? x : y;
}


int main()
{
    std::cout << "Template Test" << std::endl;
    std::cout << max(4.2f, 2) << std::endl;     // float and int
    std::cout << max('4', '7') << std::endl;    // characters
    
    return 0;
}