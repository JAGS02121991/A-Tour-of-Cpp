#include <string>

#ifndef CONTAINER_H
#define CONTAINER_H

/*
    Interface Inheritance:
        An object of a derived class can be used whenever an object of the
        base class is required. That is, the base class acts as an interface
        for the derived class. Such classes are often abstract.
*/

class Container
{
public:
    virtual ~Container() {}
    virtual double &operator[](int i) = 0;
    virtual double &operator[](int i) const = 0;
    virtual int get_index(double) = 0;
    virtual int get_size() const = 0;
    virtual std::string to_string() const = 0;
};

#endif /* CONTAINER_H */
