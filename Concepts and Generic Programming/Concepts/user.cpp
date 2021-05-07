#include <iostream>
#include "Vector.hpp"

using namespace std;

/*
    It can be invoked for any data structure that supports begin() and end() so 
    that the range- for will work. Such structures include the standard-library 
    vector , list , and map. Furthermore, the element type of the data structure 
    is limited only by its use: it must be a type that we can add to the Value 
    argument. Examples are int s, double s, and Matrix es (for any reasonable definition of Matrix ). 
    
    We could say that the sum() algorithm is generic in two dimensions: 
        - the type of the data structure used to store elements (“the sequence”)
        - the type of elements. 
    
    So, sum() requires that its first template argument is some kind of sequence 
    and its second template argument is some kind of number.

*/
template <typename Sequence, typename Number>
void sum(Sequence &sequence, Number number)
{
    for (auto &elem : sequence)
        elem += number;
}

/*
    Use of Concepts
    The Value_type of a sequence is the type of the elements in the sequence. 
    Arithmetic<X,Y> is a concept specifying that we can do arithmetic with numbers
    of types X and Y . This saves us from accidentally trying to calculate the 
    sum() of a vector<string> or a vector<int*> while still accepting vector<int> 
    and vector<complex<double>> .
*/

template <Sequence sequence, Number number>
requires Arithmetic<Value_type<sequence>, number> void sum2(sequence &seq, number num)
{
    for (auto &elem : seq)
        elem += num;
}

int main()
{
    Vector<int> v{1, 2, 3, 4, 5};

    sum2(v, 30);

    cout << v << "\n";
}