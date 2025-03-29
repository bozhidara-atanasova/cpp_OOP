#include <iostream>
using namespace std;

namespace MathOperations {
    int add(int a, int b) {
        return a + b;
    }

    int subtract(int a, int b) {
        return a - b;
    }

    int multiply(int a, int b) {
        return a * b;
    }
}
namespace BasicMath {
    int calculate(int a, int b) {
        return a + b;
    }
}

namespace AdvancedMath {
    int calculate(int a, int b) {
        return (a * a) + (b * b);
    }
}
int main() {
    cout << "Add: " << MathOperations::add(5, 3) << endl;
    cout << "Subtract: " << MathOperations::subtract(5, 3) << endl;
    cout << "Multiply: " << MathOperations::multiply(5, 3) << endl;

    // Using full namespace path
    cout << "BasicMath::calculate(2, 3): " << BasicMath::calculate(2, 3) << endl;
    cout << "AdvancedMath::calculate(2, 3): " << AdvancedMath::calculate(2, 3) << endl;

    // Using 'using namespace'
    using namespace BasicMath;
    cout << "Using BasicMath: " << calculate(10, 5) << endl;

    // Switching to AdvancedMath
    cout << "Using AdvancedMath directly: " << AdvancedMath::calculate(4, 1) << endl;

    return 0;
}
