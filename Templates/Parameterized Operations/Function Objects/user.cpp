#include "Vector.hpp"

template <typename T>
class Less_than
{
private:
    T val;

public:
    Less_than(T val) : val{val} {}

    bool operator()(const T &other)
    {
        return val < other;
    }
};

template <typename T>
class Bigger_than
{
private:
    T val;

public:
    Bigger_than(T val) : val{val} {}

    bool operator()(const T &other)
    {
        return val < other;
    }
};

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
    Vector v{1, 2, 3, 4, 5};

    std::cout << count(v, Less_than{3}) << "\n";
    std::cout << count(v, Bigger_than{4}) << "\n";
}