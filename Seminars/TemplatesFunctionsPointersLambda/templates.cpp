#include <iostream>
template<typename T>
T minValue(T a, T b)
{
    if (a > b)return b;
    else return a;
}
int main()
{
    std::cout << minValue(3, 7) << std::endl; // 3
    std::cout << minValue(5.2, 2.8) << std::endl; // 2.8
}
