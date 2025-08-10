#include <iostream>
#include <string>
//task1
class Car
{
private:
    std::string brand;
    int year;
public:
    Car(std::string b, int y)
    {
        brand = b;
        year = y;
    }
    std::string getInfo()
    {
        return "Brand " + brand + ", Year: " + std::to_string(year);
    }
};
//task2
class Employee
{
private:
    std::string name;
    double salary;
public:
    Employee(std::string n, double s)
    {
        name = n;
        salary = s;
    }
   void increaseSalary(double percent)
    {
        salary += (percent * (salary / 100));
    }
    double getSalary()
    {
        return salary;
    }
};
//task3
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
    double getArea()
    {
        return width * height;
    }
    double getPerimeter()
    {
        return 2 * width + 2 * height;
    }
};
int main()
{
    //task1
    Car c("Toyota", 2020);
    std::cout << c.getInfo();
    std::cout << std::endl;
    //task2
    Employee e("Petar", 1500);
    e.increaseSalary(10);
    std::cout << e.getSalary();
    std::cout << std::endl;
    // Exit: 1650
    //task3
    Rectangle r(5, 10);
    std::cout << r.getArea();
    // Exit: 50
}

