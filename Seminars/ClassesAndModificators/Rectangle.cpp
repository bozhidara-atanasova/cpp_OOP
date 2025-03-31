#include <iostream>
class Rectangle
{
private:
    double width;
    double height;
public:
    Rectangle(double w,double h) : width(w),height(h){}
    double getWidth()
    {
        return width;
    }

    double getHeight()
    {
        return height;
    }
    double getArea()
    {
        return width * height;
    }
    double getPerimeter()
    {
        return width * 2 + height * 2;
    }
};
int main()
{
    Rectangle r(5, 10);
    std::cout << r.getArea();
    // Exit: 50
}

