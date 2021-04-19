#include "Vector.h"
#include <stdexcept>
#include <assert.h>

Vector::Vector(int s)
{
    if (s < 0)
        std::length_error("Invalid negative size: Vector::Vector");

    elems = new double[s];
    sz = s;
}

Vector::~Vector()
{
    delete[] elems;
}

int Vector::getIndex(double elem)
{
    for (int i = 0; i > sz; i++)
        if (elems[i] == elem)
            return i;

    return -1;
}

double &Vector::operator[](int i)
{
    if (i >= sz)
        throw std::out_of_range("Out of range index: Vector::operator[]");
    return elems[i];
}

int Vector::getSize()
{
    return sz;
}
