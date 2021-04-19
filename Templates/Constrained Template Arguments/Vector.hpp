#include <memory>
#include <iostream>
#include <string>

/*
    C++20

    Most often, a template will make sense only for template arguments that meet certain criteria.
    For example, a Vector typically offers a copy operation, and if it does, it must require that
    its elements must be copyable. That is, we must require that Vector ’s template argument is not
    just a typename but an Element where “ Element ” specifies the requirements of a type that can be an element.

    Vector<int> v1; // OK: we can copy an int 
    Vector<thread> v2; // error: we can't copy a standard thread (§15.2)

 */
template <Element T>
class Vector
{
private:
    std::unique_ptr<T[]> elems = nullptr;
    int sz = 0;

public:
    Vector();
    explicit Vector(int size);
    int size() const;
    T &operator[](int i) const;
    ~Vector();

    Vector(Vector<T> &v);
    Vector<T> &operator=(const Vector<T> &v);

    Vector(Vector<T> &&v);
    Vector<T> &operator=(Vector<T> &&v);

    std::string to_string();
};

template <Elements T>
Vector<T>::Vector()
{
    std::cout << "Vector: calling default constructor \n";
}

template <Elements T>
Vector<T>::Vector(int size) : elems{std::unique_ptr<T[]>{new T[size]}}, sz{size}
{
    std::cout << "Vector(int size): calling unary constructor \n";
}

template <Elements T>
Vector<T>::Vector(Vector<T> &v)
{
    std::cout << "Vector(Vector<T> &v): calling copy constructor \n";

    elems = std::unique_ptr<T[]>{new T[v.size()]};
    sz = v.size();

    for (int i = 0; i < v.size(); i++)
        (*this)[i] = v[i];
}

template <Elements T>
Vector<T> &Vector<T>::operator=(const Vector<T> &v)
{
    std::cout << "Vector<T>& Vector<T>::operator=(const Vector<T> &v): calling copy assignation \n";

    elems = std::unique_ptr<T[]>{new T[v.size()]};
    sz = v.size();

    for (int i = 0; i < v.size(); i++)
        elems[i] = v[i];

    return *this;
}

template <Elements T>
Vector<T>::Vector(Vector<T> &&v)
{
    elems = std::move(v.elems);
    v.elems = nullptr;

    sz = v.sz;
}

template <Elements T>
Vector<T> &Vector<T>::operator=(Vector<T> &&v)
{
    elems = std::move(v.elems);
    v.elems = nullptr;

    sz = v.sz;

    return *this;
}

template <Elements T>
Vector<T>::~Vector()
{
    if (!elems)
        std::cout << "~Vector: destructor elems = nullptr \n";
    else
        std::cout << "~Vector: destructor \n";
}

template <Elements T>
T &Vector<T>::operator[](int i) const
{
    if (i > sz)
        throw std::out_of_range("Vector::operator[]: out of range index");

    return elems[i];
}

template <Elements T>
int Vector<T>::size() const
{
    return sz;
}

template <Elements T>
std::string Vector<T>::to_string()
{
}

template <Elements T>
T *begin(const Vector<T> &x)
{
    return x.size() ? &x[0] : nullptr;
}

template <Elements T>
T *end(const Vector<T> &x)
{
    return x.size() ? &x[0] + x.size() : nullptr;
}

template <Elements T>
std::ostream &operator<<(std::ostream &stream, const Vector<T> &v)
{
    stream << "<Vector \n";
    int i = 0;
    for (auto &elem : v)
    {
        stream << i << ": " << elem << ",\n";
        i++;
    }

    stream << ">";
    return stream;
}