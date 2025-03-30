#include <iostream>
#include <functional>
//templatefunctons
template <typename T>
T maxValue(T a, T b)
{
    return (a > b) ? a : b;
}
//high order functions
int add(int a, int b)
{
    return a + b;
}
//function in function
int applyOperations(int x, int y, int (*operation)(int, int))
{
    return operation(x, y);
}
//std::function
int multiply(int a, int b) {
    return a * b;
}
int applyOperation(int x, int y, std::function<int(int, int)> operation) {
    return operation(x, y);
}
//lambda function
int applyOperation2(int x, int y, std::function<int(int, int)> operation)
{
    return operation(x, y);
}
int main()
{
    std::cout << maxValue(5, 10) << std::endl;
    std::cout << maxValue(5.3434, 4.433) << std::endl;

    int (*funcptr)(int, int) = add;
    std::cout << funcptr(3, 4) << std::endl;

    std::cout << applyOperations(10, 20, add) << std::endl;

    std::function<int(int, int)> operation = multiply;
    std::cout << operation(5, 3) << std::endl; // 15
    std::cout << applyOperation(10, 20, [](int a, int b) { return a + b; }) << std::endl; // 30
    
    std::cout << applyOperation(10, 20, [](int a, int b) { return a * b; }) << std::endl; // 200
    return 0;

    
}
