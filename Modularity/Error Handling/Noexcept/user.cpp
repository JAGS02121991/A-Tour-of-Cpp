#include "Vector.h"
#include <numeric>

// A function that should never throw can be declared as noexept
void fillWithMonotonicallyIncNumbers(Vector &v) noexcept
{
    std::iota(&v[0], &v[v.getSize() + 1], 1);
}
/* 
    If all good intent and planning fails, so that user still throws, std::terminate() is called to immediately
    terminate the program
*/

int main()
{
    Vector v = Vector(10);
    fillWithMonotonicallyIncNumbers(v);
}