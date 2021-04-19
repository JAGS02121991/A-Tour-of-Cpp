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

Vector::Vector(Vector &&other) : elems{nullptr}, sz{0}
{
    elems = other.elems;
    sz = other.sz;

    other.elems = nullptr;
    other.sz = 0;
}

Vector::~Vector()
{
    /*
        Vector ’s constructor allocates some memory on the free store (also called the heap or dynamic store ) 
        using the new operator. The destructor cleans up by freeing that memory using the delete[] operator.
        Plain delete deletes an individual object, delete[] deletes an array.

        The technique of acquiring resources in a constructor and releasing them in a destructor, known as
        Resource Acquisition Is Initialization or RAII.

        allows us to eliminate “naked new operations,” that is, to avoid allocations in general code and keep
        them buried inside the implementation of well-behaved abstractions. Similarly, “naked delete operations”
        should be avoided. Avoiding naked new and naked delete makes code far less error-prone and far easier to
        keep free of resource leaks
    */
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