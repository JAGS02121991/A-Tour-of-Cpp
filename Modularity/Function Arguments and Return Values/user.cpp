#include "Vector.h"
#include <iostream>

/*
    Given the importance of passing information to and from functions, 
    it is not surprising that there are a variety of ways of doing it.
    
    Key concerns are:
        - Is an object copied or shared?
        - If an object is shared, is it mutable?
        - Is an object moved, leaving an "empty object" behind?

    The default behavior for both argument passing and value return is “copy” (§ 1.9 ),
    but some copies can implicitly be optimized to moves.
    
    In the sum() example, the resulting int is copied out of sum() but it would be
    inefficient and pointless to copy the potentially very large vector into sum(), 
    so the argument is passed by reference (indicated by the &).
    
    The sum() has no reason to modify its argument. This immutability is indicated by
    declaring the vector argument const (§ 1.6 ), so the vector is passed by const -reference.
*/

int sum(const Vector &v)
{
    int sum = 0;
    for (int i = 0; i < v.getSize(); i++)
        sum += v[i];

    return sum;
}

int main()
{
    Vector v = Vector(5);
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;
    v[3] = 4;
    v[4] = 5;

    std::cout << sum(v);
}