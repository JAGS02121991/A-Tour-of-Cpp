import Vector;
#include <cmath>

double sqrt_sum(Vector &v)
{
    int sum = 0;
    for (int i = 0; i < v.getSize(); i++)
    {
        sum += std::sqrt(v[i]);
    }
    return sum;
}