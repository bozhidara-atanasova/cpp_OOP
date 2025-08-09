#include <iostream>
//task1
template<typename T>
void swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}
//task2
template <typename Y>
Y findMin(Y arr[], Y number)
{
    Y temp = arr[0];
    for (Y i = 0; i < number; i++)
    {
        if (temp > arr[i])temp = arr[i];
    }
    return temp;
}
//task 3
template <typename T>
class Calculator {
public:
    static T add(T a, T b) {
        return a + b;
    }

    static T subtract(T a, T b) {
        return a - b;
    }

    static T multiply(T a, T b) {
        return a * b;
    }

    static T divide(T a, T b) {
        if (b == 0) {
            throw std::runtime_error("We can't divide by 0!");
        }
        return a / b;
    }
};

int main()
{
    int a = 5, b = 10;
    swap(a, b);
    std::cout << a << " " << b << std::endl; 
    int numbers[] = { 5, 3, 8, 1, 7 };
    std::cout << findMin(numbers, 5) << std::endl;
    std::cout << Calculator<int>::add(5, 3) << std::endl;
    std::cout << Calculator<double>::multiply(2.5, 3.0) << std::endl;
    return 0;
}