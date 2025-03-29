#include <iostream>
//struct
struct Point
{
    int x;
    int y;
};
//enum
enum Color{RED, GREEN, BLUE}; //makes the code more readable
//enum class
enum class Status {OK, ERROR, UNKNOWN};
//union
union Data
{
    int i;
    float f;
    char std[20];
}; //we use it when we want to use the same memory for diffrent purposes
//typedef and using
typedef unsigned int uint;
using ulong = unsigned long;
//namespace
namespace Math {
    const double PI = 3.14159;
    double square(double x) { return x * x; }
}

int main()
{
    //1
    Point p1 = { 10, 20 };
    std::cout << "X: " << p1.x << " , Y: " << p1.y << std::endl;
    //2
    Color c = GREEN;
    if (c == GREEN)
    {
        std::cout << "The color is GREEN" << std::endl;
    }
    //3
    Status s = Status::OK;
    //4
    Data data;
    data.i = 10;
    std::cout << "data.i: " << data.i << std::endl;
    data.f = 220.5;
    std::cout << "data.f: " << data.f << std::endl;
    //5
    uint a = 100;
    ulong b = 100000;
    //6
    std::cout << "PI: " << Math::PI << std::endl;
    std::cout << "Square of 4: " << Math::square(4) << std::endl;

    return 0;

}
//the diffrence between struct and classes is that the struct members are public by default
//In the class the members are private by default
//struct is used for simpler data structures, while class is used for more complicated objects
