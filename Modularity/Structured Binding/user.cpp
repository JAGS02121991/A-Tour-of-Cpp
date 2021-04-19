#include <string>
#include <iostream>
#include <map>

using namespace std;

struct Entry
{
    string name;
    int value;
};

Entry read_entry(istream &is)
{
    string s;
    int i;
    is >> s >> i;

    return {s, i};
}

void increment(map<string, int> &m, int increment)
{
    for (auto &[key, value] : m)
        value += increment;
}

int main()
{
    auto entry = read_entry(cin);

    cout << entry.name << ", " << entry.value << "\n";

    auto [name, value] = read_entry(cin);

    cout << name << ", " << value << "\n";

    map<string, int> m; // note: default constructor

    m.insert(pair<string, int>("hello", 10));
    m.insert(pair<string, int>("wassap", 20));
    m.insert(pair<string, int>("heya!", 30));

    for (auto [key, value] : m)
        cout << "Key: " << key << ", Value: " << value << "\n";

    increment(m, 13);

    for (auto [key, value] : m)
        cout << "Key: " << key << ", Value: " << value << "\n";

    /*
        When structured binding is used for a class with no private data, it is easy to see how the binding is done: 
        there must be the same number of names defined for the binding as there are nonstatic data members of the class,
        and each name introduced in the binding names the corresponding member.
    */
}