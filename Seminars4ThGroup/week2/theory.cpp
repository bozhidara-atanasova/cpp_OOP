#include <iostream>
#include <functional>
//templates
template <typename T>
T maxValue(T a, T b)
{
    return (a > b) ? a : b;
}
//higher order-functions
int add(int a, int b)
{
    return a + b;
}
int applyOperation(int x, int y, int(*operation)(int, int))
{
    return operation(x, y);
}
//std::function
int multiply(int a, int b)
{
    return a * b;
}
int applyOperation2(int x, int y, std::function<int(int, int)> operation)
{
    return operation(x, y);
}
int main()
{
    std::cout << maxValue(5, 10) << std::endl;   
    std::cout << maxValue(3.14, 2.71) << std::endl; 
    int(*funcPtr)(int, int) = add;
    std::cout << funcPtr(3, 4) << std::endl;
    std::cout << applyOperation(19, 20, add) << std::endl;
    std::function<int(int, int)> operation = multiply;
    std::cout << operation(5, 3) << std::endl;
    std::cout << applyOperation2(10, 20, [](int a, int b) {return a + b; }) << std::endl;
    auto sum = [](int a, int b) { return a + b; };
    std::cout << sum(3, 4) << std::endl; // 7
    return 0;
}

