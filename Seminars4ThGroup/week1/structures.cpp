#include <iostream>
struct Point
{
    int x;
    int y;
};
struct Vector2D
{
    double x, y;
    Vector2D(double x = 0, double y = 0) : x(x) , y(y) {}

    void add(const Vector2D& other)
    {
        x += other.x;
        y += other.y;
    }
    void print() const
    {
        std::cout << "Vector(" << x << ", " << y << ")\n";
    }
};
int main()
{
    Point p1 = { 10,20 };
    std::cout << "X: " << p1.x << ",Y: " << p1.y << std::endl;
    Vector2D v1 = { 7,8 };
    v1.print();
    Vector2D delta = { 3,6 };
    v1.add(delta);
    v1.print();
    return 0;
}

