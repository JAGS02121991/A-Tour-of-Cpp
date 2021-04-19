#include "Complex.h"
#include <iostream>

int main()
{
    Complex z{1, 0};
    const Complex cz{1, 3};

    /*
        A const member function can be invoked for both const and non- const objects, 
        but a non- const member function can only be invoked for non- const objects.
    */
    z = cz;
    // cz = z; // Error

    std::cout << z + cz << "\n"
              << z - cz << "\n"
              << z * cz << "\n"
              << z / cz << "\n";
}
