/*
    Variadic Templates
    A template can be defined to accept an arbitrary number template . Consider a simple function
*/

#include <iostream>
#include "Vector.hpp"

using namespace std;

void print() {}

template <typename T, typename... Tail>
void print(T value, Tail... tail)
{
    cout << value << " ";

    /* 
        A call of print() separates the arguments into a head (the first) and a tail (the rest). 
        The head is printed and then print() is called for the tail. Eventually, of course, 
        tail will become empty, so we need the no-argument version of print() to deal with that. 
        If we can eliminate that print() using a compile-time if
    */

    //if constexpr (sizeof...(tail) > 0)
    print(tail...);
}

int main()
{
    Vector<int> v{1, 2, 3, 4, 5};
    print("Hello", "friend", 10, 12.4, v);
}

/* 

    The strength of variadic templates (sometimes just called variadics ) is that they can accept 
    any arguments you care to give them. Weaknesses include The recursive implementations can be
    tricky to get right. 
        - The recursive implementations can be surprisingly expensive in compile time. 
        - The type checking of the interface is a possibly elaborate template program. 
        - Because of their flexibility, variadic templates are widely used in the standard library, 
          and occasionally wildly overused.

*/

