#include <iostream>
int add(int a, int b)
{
	return a + b;
}
int applyOperation(int x, int y, int (*operation)(int, int))
{
	return operation(x,y);
}
template <typename T>
T multiply(T a, T b)
{
	return a * b;
}
template <typename T>
T applyOperation2(T x, T y, T(*operation)(T, T))
{
	return operation(x, y);
}
int main()
{
	std::cout << applyOperation(10, 20, add) << std::endl; // 30
	std::cout << applyOperation2(10, 20, multiply) << std::endl; // 200
}

