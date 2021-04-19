#include "Vector.h"
#include <stdexcept>
#include <iostream>

Vector add(Vector &x, Vector &y)
{
    if (x.getSize() != y.getSize())
        throw std::length_error("x and y have different sizes: add(Vector &x, Vector &y)");

    /*
        A Vector may be very large and expensive to copy even on modern hardware.
        So we don’t copy, we give Vector a move constructor (See Vector.cpp) and very cheaply move the Vector out of add function.
        We do not need to regress to using manual memory management using heap and pointers.
    */
    Vector sum = Vector(x.getSize());

    for (int i = 0; i < x.getSize(); i++)
        sum[i] = x[i] + y[i];

    return sum;
}

int main()
{
    Vector x = Vector(3);
    Vector y = Vector(3);

    x[0] = 1;
    x[1] = 2;
    x[2] = 3;

    y[0] = 1;
    y[1] = 2;
    y[2] = 3;

    std::cout << add(x, y);
}