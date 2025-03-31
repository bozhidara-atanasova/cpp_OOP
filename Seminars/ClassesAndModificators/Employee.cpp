#include <iostream>
#pragma warning(disable : 4996)
class MyString
{
private:
    char* data;
    size_t length;
public:
    MyString() : data(nullptr), length(0) {}

    MyString(const char* str)
    {
        length = std::strlen(str);
        data = new char[length + 1];
        std::strcpy(data, str);
    }
    MyString(const MyString& other) {
        length = other.length;
        data = new char[length + 1];
        std::strcpy(data, other.data);
    }
    MyString& operator=(const MyString& other) {
        if (this != &other) {
            delete[] data;
            length = other.length;
            data = new char[length + 1];
            std::strcpy(data, other.data);
        }
        return *this;
    }
    ~MyString() {
        delete[] data;
    }

    char& operator[](size_t index) {
        return data[index];
    }

    friend std::ostream& operator<<(std::ostream& os, const MyString& str) {
        if (str.data) {
            os << str.data;
        }
        return os;
    }

    const char& operator[](size_t index) const {
        return data[index];
    }

    size_t size() const {
        return length;
    }

    void print() const {
        if (data)
            std::cout << data;
    }
};
class Employee
{
private:
    MyString name;
    double salary;
public:
    Employee(const MyString& n,double s) : name(n),salary(s) {}

    double increaseSalary(double percent)
    {
        return salary = salary + salary * (percent / 100.0);
    }
    void getSalary()
    {
        std::cout << "The salary is: " << salary;
    }
};
int main()
{
    Employee e("Петър", 1500);
    e.increaseSalary(10);
    e.getSalary();// Exit: 1650
    
}
