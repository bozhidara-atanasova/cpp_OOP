#include <iostream>
#include <cassert>
using namespace std;
class Rectangle
{
private:
    double width;
    double height;
public:
    Rectangle(double w, double h)
    {
        width = w;
        height = h;
    }
    double area()
    {
        return width * height;
    }
    double perimeter()
    {
        return width * 2 + height * 2;
    }
    void resize(double factor)
    {
        width = width * factor;
        height = height * factor;
    }
    double getWidth() { return width; }
    double getHeight() { return height; }
  
};
int main()
{
    Rectangle r1(4.0, 5.0);
    assert(r1.area() == 20.0);

    assert(r1.perimeter() == 18.0);

    r1.resize(2.0);
    assert(r1.getWidth() == 8.0);
    assert(r1.getHeight() == 10.0);
    assert(r1.area() == 80.0);
    assert(r1.perimeter() == 36.0);

    Rectangle r2(10.0, 4.0);
    r2.resize(0.5);
    assert(r2.getWidth() == 5.0);
    assert(r2.getHeight() == 2.0);
    assert(r2.area() == 10.0);
    assert(r2.perimeter() == 14.0);


    return 0;
}
