/*
    Concept Definition
    A concept is a compile-time predicate specifying how one or more types can be used. 
*/

template<typename T>
concept Equality_comparable = 
    requires (T a, T b) {
        { a == b } -> bool,
        { a != b } -> bool
    }

/* 
    Equality_comparable is the concept we use to ensure result 
    of those operations must be convertible to bool.
*/

/*
    We can define Equality_comparable for nonhomogeneous comparisons
*/

template<typename T, typename T2 = T>
concept Equality_comparable =
    requires (T a, T2 b) {
        { a == b } -> bool,
        { a != b } -> bool,
        { b == a } -> bool,
        { b != a } -> bool
    }

/*
    The typename T2 =T says that if we don’t specify a second template argument, 
    T2 will be the same as T ; T is a default template argument .
*/


int main() {
    static_assert(Equality_comparable<int>); // succeds

    struct s
    {
        int a;
    };

    static_assert(Equality_comparable<S>); // fails because structs don't have == and != by default


    static_assert(Equality_comparable<int, double>);
}