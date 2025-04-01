#include <iostream>
#pragma warning(disable:4996)
class Time
{
private:
    int hours;
    int minutes;
public:
    Time(int h = 0, int m = 0)
    {
        hours = h + m / 60;
        minutes = m % 60;
    }
    Time operator+(const Time& other) const
    {
        int totalMinutes = minutes + other.minutes;
        int totalHours = hours + other.hours + totalMinutes / 60;
        totalMinutes %= 60;
        return Time(totalHours, totalMinutes);
    }
    bool operator==(const Time& other) const {
        return (hours == other.hours && minutes == other.minutes);
    }
    bool operator<(const Time& other) const {
        if (hours < other.hours)
            return true;
        else if (hours == other.hours)
            return minutes < other.minutes;
        else
            return false;
    }
    void print() const {
        std::cout << (hours < 10 ? "0" : "") << hours << ":"
            << (minutes < 10 ? "0" : "") << minutes << std::endl;
    }
};
int main()
{
    Time t1(2, 45);
    Time t2(1, 30);

    Time sum = t1 + t2;
    sum.print();  // 04:15

    if (t1 == t2)
        std::cout << "Times are equal" << std::endl;
    else
        std::cout << "Times are not equal" << std::endl;

    if (t1 < t2)
        std::cout << "t1 is earlier" << std::endl;
    else
        std::cout << "t2 is earlier or equal" << std::endl;

    return 0;
}
