#include <iostream>
//task1
template <typename T>
T minValue(T x, T y)
{
    return(x < y) ? x : y;
}
//task2
int applyOperation(int x, int y, int(*operation)(int, int))
{
    return operation(x, y);
}
int add(int a, int b) { return a + b; };

int main()
{
    std::cout << minValue(5.2, 2.8) << std::endl;
    std::cout << minValue(3, 7);
    
    std::cout << applyOperation(10, 20, add) << std::endl; // 30
    return 0;
}

