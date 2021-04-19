#include <iostream>

using namespace std;

void my_print(int x) {
    cout << "Integer: " << x << "\n";
}

void my_print(float x) {
    cout << "Float: " << x << "\n";
}

int main() {
    my_print((int)10);
    my_print((float)10.5);
}