#include <iostream>
#include <vector>
#include <list>

using namespace std;

/*
    The compiler will select the template with the strongest requirements met by the arguments. 
    In this case, a list only supplies forward iterators, but a vector offers random-access iterators.
*/

template <Forward_iterator Iter>
void advance(Iter p, int n)
{
    while (--n)
        ++p;
}

template <Random_access_iterator Iter>
void advance(Iter p, int n)
{
    p += n;
}

int main()
{
    vector<int> v{1, 2, 3, 4, 5};
    list<int> l{1, 2, 3, 4, 5};

    advance(v); // Will use the fast random access iterator
    advance(l); // Will use the slow forward acess iterator
}