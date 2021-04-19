#include "Vector.h"
#include <stdexcept>
#include <assert.h>
#include <iostream>

Vector::Vector(int s)
{
    if (s < 0)
        std::length_error("Invalid negative size: Vector::Vector");

    elems = new double[s];
    sz = s;
}

// Move Constructor
Vector::Vector(Vector &&other) : elems{nullptr}, sz{0}
{
    elems = other.elems;
    sz = other.sz;

    other.elems = nullptr;
    other.sz = 0;
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

double &Vector::operator[](int i) const
{
    if (i >= sz)
        throw std::out_of_range("Out of range index: Vector::operator[]");
    return elems[i];
}

int Vector::getSize() const
{
    return sz;
}

std::ostream &operator<<(std::ostream &stream, const Vector &v)
{
    for (int i = 0; i < v.getSize(); i++)
        stream << i << ": " << v[i] << ", ";

    return stream;
}