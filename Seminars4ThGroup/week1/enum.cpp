#include <iostream>
enum Day
{
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
};

enum Direction {
    Up,
    Down,
    Left,
    Right
};
struct Vector2D
{
    double x, y;

    Vector2D(double x = 0, double y = 0) : x(x), y(y) {}

    void move(Direction dir, double amount = 1.0)
    {
        switch (dir) {
        case Up:    y += amount; break;
        case Down:  y -= amount; break;
        case Right: x += amount; break;
        case Left:  x -= amount; break;
        }
    }
    void print() const {
        std::cout << "Vector(" << x << ", " << y << ")\n";
    }
};

int main()
{
    Day today = Wednesday;
    if (today == 2) std::cout << "It's wednesday";
    Vector2D player(0, 0);
    player.print();

    player.move(Right, 5);
    player.move(Up, 3);
    player.print(); // Vector(5, 3)

    return 0;
    return 0;
}

