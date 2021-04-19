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

/*
    Here, I just mention two favorites:
        Initializer-list constructor : Initialize with a list of elements. 
        push_back() : Add a new element at the end of (at the back of) the sequence.
*/

//Initializer-list constructor : Initialize with a list of elements.
Vector::Vector(std::initializer_list<double> list) : elems{new double[list.size()]}, sz{static_cast<int>(list.size())}
{
    std::copy(list.begin(), list.end(), elems);
}

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

void Vector::push_back(double element)
{
    // Use efficient strategy to dinamically increase and decrease size, like table doubling strategy
}

std::ostream &operator<<(std::ostream &stream, const Vector &v)
{
    for (int i = 0; i < v.getSize(); i++)
        stream << i << ": " << v[i] << ", ";

    return stream;
}