#include <iostream>

enum TrafficLight
{
    Red,
    Yellow,
    Green
};

TrafficLight calculate(int r, int y, int g, int t)
{
    int time = t % (r + y + g);
    if (time < r)
        return Red;
    else if (time < r + y)
        return Yellow;
    else
        return Green;
}

void printMessage(TrafficLight state)
{
    switch (state)
    {
    case Red:
        std::cout << "Stay calm, it's red!\n";
        break;
    case Yellow:
        std::cout << "Attention, yellow light!\n";
        break;
    case Green:
        std::cout << "Go, it's green!\n";
        break;
    }
}

int main()
{
    int r, y, g, t;
    std::cin >> r >> y >> g >> t;

    TrafficLight state = calculate(r, y, g, t);
    printMessage(state);

    return 0;
}
