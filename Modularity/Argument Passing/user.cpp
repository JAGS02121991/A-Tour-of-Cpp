#include "Vector.h"
#include <stdexcept>
#include <iostream>

void sum(const Vector &x, const Vector &y)
{
    // Since x and y are constant references, this means that they will not be changed
    // and yet they are only references, so no copy is done when passing this two params
}

int sum(Vector &x, Vector &y)
{
    // Since x and y are references, this means we can expect x and y to change
    // and since they are references, changes to x and y will have repercusions
    // to the state of the original objects
}

int sum(Vector x, Vector y)
{
    // Since x and y and plain objects, this means that we are dealing with copies
    // of the original two objects passed to sum
}

int sum(Vector *x, Vector *y)
{
    // Since x and y are pointers, this means we are dealing with memory addresses
    // this means can expect changes to the original objects that this pointers point to
}