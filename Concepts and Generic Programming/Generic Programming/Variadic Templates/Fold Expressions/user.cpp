#include <vector>
#include <iostream>

using namespace std;

/*

    To simplify the implementation of simple variadic templates, C++17 offers a 
    limited form of iteration over elements of a parameter pack.

*/

template <typename... Value>
int sum(Value... values)
{
    return (values + ... + 0);
    // sum(1, 2, 3)
    // (3 + (2 + (1 + (0))))
}

template <typename... Value>
void print(Value... values)
{
    (cout << ... << values) << '\n';
}

template <typename Res, typename... Ts>
vector<Res> to_vector(Ts &&...args)
{
    vector<Res> res;

    // https://stackoverflow.com/questions/33868486/parameter-packs-not-expanded-with
    (res.push_back(args), ...);

    return move(res);
}

template <typename... Ts>
int factorial(Ts &&...factors)
{
    vector<int> factors_container = to_vector<int>(factors...);

    // factorial(1, 2, 3, 4)
    return (factors * ... * 1); // (1*(2*(3(4)))) right to left
    //return (1 * ... * factors); // (4*(3*(2(1)))) left to righ
}

int main()
{
    cout << sum(1, 2, 3) << "\n";

    print("Hello ", "mofo ", "watsapp \n");

    auto a = 1;
    auto b = 2;
    auto c = 3;

    auto v = to_vector<int>(a, b, c);

    for (auto elem : v)
        cout << elem << " ";

    auto res = factorial(1, 2, 3, 4);
}