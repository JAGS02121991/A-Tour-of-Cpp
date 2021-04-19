#include "Vector.h"
#include <iostream>

int main()
{
    Vector v{1, 2, 3, 4, 5};
    std::cout << v << "\n";

    v.push_back(6);
}