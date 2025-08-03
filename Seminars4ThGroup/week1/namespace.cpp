#include <iostream>

namespace Math {
    const double PI = 3.14159;
    double square(double x) { return x * x; }
}

int main() {
    std::cout << "PI: " << Math::PI << std::endl;
    std::cout << "Square of 4: " << Math::square(4) << std::endl;
    return 0;
}