#include <iostream>

using namespace std;

int main()
{
    char a[]{'a', 'b', 'c', 'd'};

    char *b = &a[1]; // b points to a's second element

    char x = *b; // *b is the object b points to

    char src[]{'a', 'b', 'c', 'd', 'e'};
    char dest[5];

    for (int i = 0; i < 5; i++)
    {
        dest[i] = src[i];
    }

    for (auto x : dest)
    {
        cout << x << "\n";
    }

    for (auto &x : src)
    {
        ++x; // Modifies the elements in src because we are using a reference.
    }

    for (auto x : src)
    {
        cout << x << "\n";
    }
}