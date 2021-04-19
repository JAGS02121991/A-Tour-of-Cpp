int main()
{
    double d = 2.3;
    double d2{2.3};
    double d4 = {2.3};

    int x = double(2000000000); // Can narrow
    int y{double(2000000000)}; // Cannot narrow

    // the = is optional with the {}

    // complex<double> z = 1;
    // complex<double> z2 = {d, d2};
    // complex<double> z3{d, d2};

    // vector<int> v{1, 2, 3, 4, 5};
}