#include "Vector.h"

int main()
{
    int n = 20;

    Vector v(n);

    {
        Vector v2(2 * n);
    } //v2 is destroyed
} //v1 is destroyed