/*
    There is currently no general and standard way of writing optional run-time tests of invariants, 
    preconditions, etc. A contract mechanism is proposed for C++20 [ Garcia,2016 ] [ Garcia,2018 ].
    The aim is to support users who want to rely on testing to get programs right by running
    with extensive run-time checks but then deploy code with minimal checks.
*/

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
    /*
        For now, we have to rely on ad hoc mechanisms. 
        For example, we could use a command-line macro to control a run-time check:
    */
    if (RANGE_CHECK && i >= sz)
        throw std::out_of_range("Out of range index: Vector::operator[]");
    return elems[i];
}

int Vector::getSize()
{
    return sz;
}

void foo(const char *p)
{
    /*
        The standard library offers the debug macro, assert() , to assert that a condition must hold at run time.
    */
    assert(p != nullptr);
    /*
        If the condition of an assert() fails in “debug mode,” the program terminates.
        If we are not in debug mode, the assert() is not checked. That’s pretty crude and inflexible, but often sufficient.
    */
}
