#include <iostream>

using namespace std;

double square(double x) {
    // type: double(double)
    return x * x;
}

void print_square(double x) {
    cout << "The square of " << x << " is " << square(x) << "\n";
}

int main() {
    print_square(1.234);
}