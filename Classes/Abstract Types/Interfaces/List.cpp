#include <list>
#include <string>
#include "List.h"

List::List(int s) : elems{new std::list<double>(s)} {}
List::List(std::initializer_list<double> list) : elems{new std::list<double>(list.size())}
{
    auto listIt = list.begin();
    for (double &elem : *elems)
    {
        elem = *listIt;
        ++listIt;
    }
}
List::List(List &&other) : elems{nullptr}
{
    elems = other.elems;

    other.elems = nullptr;
}
List::~List()
{
    delete elems;
}
double &List::operator[](int i)
{
    for (auto &elem : *elems)
    {
        if (i == 0)
            return elem;

        --i;
    }
    throw std::out_of_range{"List Container"};
}
double &List::operator[](int i) const
{
    for (auto &elem : *elems)
    {
        if (i == 0)
            return elem;

        --i;
    }
    throw std::out_of_range("Out of range index List::operator[]");
}
int List::get_index(double input)
{
    int i = 0;
    for (double elem : *elems)
    {
        if (input == elem)
            return i;
        ++i;
    }
    return i;
}
int List::get_size() const
{
    return (*elems).size();
}
std::string List::to_string() const
{
    std::string output = "";
    int i = 0;
    for (auto elem : *elems)
    {
        output += std::to_string(i) + ": " + std::to_string(elem) + ", ";
        ++i;
    }
    output = "<List " + output + " >";
    return output;
}