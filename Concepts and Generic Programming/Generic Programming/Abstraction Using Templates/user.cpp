/* 
    Good abstractions are carefully grown from concrete examples. 
    It is not a good idea to try to “abstract” by trying to prepare 
    for every conceivable need and technique; in that direction lies
    inelegance and code – concrete examples from real use and try to
    eliminate inessential details. 
    
    Consider:
*/
#include <vector>

using namespace std;

double sum(const vector<int> &seq)
{
    double res = 0;

    for (auto &elem : seq)
        res += elem;

    return res;
}

/* 

    This is obviously one of many ways to compute the sum of a sequence of numbers. 
    Consider what makes this code less general than it needs to be: 
        Why just int s? 
        Why just vector s? 
        Why accumulate in a double ? 
        Why start at 0 ?
        Why add?
*/

template <typename Iter, typename Val>
Val accumulate(Iter first, Iter last, Val res)
{
    for (auto p = first; p != last; ++p)
        res += *p;

    return res;
}

/*
    The data structure to be traversed has been abstracted into a pair of iterators 
    representing a sequence. 
 */

void use(vector<int> &a, vector<double> &b)
{
    accumulate(a.begin(), a.end(), 0);

    accumulate(b.begin(), b.end(), 15.3);
}

/* 
    The process of generalizing from a concrete piece of code (and preferably from several) 
    while preserving performance is called lifting . 
    
    Conversely, the best way to develop a template is often to first, 
        - write a concrete version
        - then, debug, test, and measure it 
        - finally replace the concrete types with template arguments.


    Naturally, the repetition of begin() and end() is tedious, so we can 
    simplify the user interface a bit:
*/

template <Range R, Number Val>
Val accumulate(R sequence, Val res)
{
    for (auto it = begin(sequence); it != end(sequence); ++it)
        res += *it;
    return res;
}

/* 
    For full generality, we can abstract the += operation
*/