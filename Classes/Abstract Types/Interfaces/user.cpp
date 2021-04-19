#include <iostream>
#include "Container.h"
#include "Vector.h"
#include "List.h"

void add(Container &items, double ammount)
{
    for (int i = 0; i < items.get_size(); i++)
        items[i] += ammount;
}

void print(Container &items)
{
    std::cout << items.to_string() << "\n";
}

int main()
{
    Vector v{1, 2, 3, 4, 5};

    add(v, 20);
    print(v);

    List l{6, 7, 8, 9, 10};
    add(l, 30);
    print(l);
}