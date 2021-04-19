#include <string>
#include <variant>
#include <iostream>

using namespace std;

struct Node
{
public:
    Node(int *elems) : elems{elems}
    {
    }

private:
    int *elems;
};

union Value
{
    //error prone, how do you know which one is it?
    //You have to manually test, use variant instead or
    //encapsulate in a class
    Node *p;
    int i;
};

struct Entry
{
    string name;

    variant<Node *, int> v;
    //Value v;

    //int t;
    //Node* p;
};

void foo(Entry *pe)
{
    // variant give you a safe way to know if it is one or the other
    if (holds_alternative<int>(pe->v))
        cout << get<int>(pe->v);
    else
        cout << get<Node *>(pe->v);
}
