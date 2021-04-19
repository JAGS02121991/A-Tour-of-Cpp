#include "Vector.hpp"

template <typename Sequence, typename Operation>
int count(Sequence &sequence, Operation predicate)
{
    int count = 0;
    for (auto &elem : sequence)
        if (predicate(elem))
            count++;

    return count;
}

int main()
{
    /*
        The notation [&](int a){ return a<x; } is called a lambda expression. 

        The compiler compiles lambda functions to "Function Object" exactly like Less_than<int>{x}. 

        The [&] is a capture list specifying that all local names used in 
        the lambda body (such as x ) will be accessed through references.
        Had we wanted to “capture” only x , we could have said so: [&x].
        Had we wanted to give the generated object a copy of x, we could have said so: [=x].
        Capture nothing is [ ].
        Capture all local names used by reference is [&].
        Capture all local names used by value is [=] .
    */

    Vector v{1, 2, 3, 4, 5};
    int threshold = 3;

    std::cout << count(v, [&](int x) { return x < v.size() - 2; }) << "\n"; // We use a reference for all vars inside lambda (in this case only v)
    std::cout << count(v, [=](int x) { return x > threshold; }) << "\n";    // We use a copy for all vars inside lambda (in this case only threshold)

    std::cout << count(v, [&v](int x) { return x < v.size() - 2; }) << "\n";          // We use a reference to v inside lambda
    std::cout << count(v, [&threshold](int x) { return x > threshold - 2; }) << "\n"; // We use a reference to threshold inside lambda

    std::cout << count(v, [](auto x) { return x > 20; }) << "\n"; // We can use auto to make the lambda "generic"
}