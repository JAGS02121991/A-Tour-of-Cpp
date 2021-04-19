/*
    How to compile a file with several header and cpp files?
    https://stackoverflow.com/questions/3202136/using-g-to-compile-multiple-cpp-and-h-files
*/

#include "Vector.h"
#include <cmath>
#include <iostream>

using namespace std;

double sqrt_sum(Vector &v)
{
    double sum_of_sqrt_roots = 0;
    for (int i = 0; i < v.getSize(); i++)
    {
        sum_of_sqrt_roots += std::sqrt(v[i]);
    }
    return sum_of_sqrt_roots;
}

int main()
{
    Vector v = Vector(5);
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;
    v[3] = 4;
    v[4] = 5;

    cout << "Sqrt sum is: " << sqrt_sum(v);
}