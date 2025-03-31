#include <iostream>
#pragma warning(disable : 4996)
#include <cstring>

class MyString
{
private:
    char* data;
    size_t length;
public:
    MyString() : data(nullptr) , length(0) {}

    MyString(const char* str)
    {
        length = std::strlen(str);
        data = new char[length + 1];
        std::strcpy(data,str);
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
class Car
{
private:
    MyString brand;
    int year;
public:
    Car(const MyString& b,int y) : brand(b),year(y) {}

    void getInfo()
    {
        std::cout << "Brand: " << brand << " , year:" << year;
    }
};
int main()
{
    Car c("Toyota", 2020);
    c.getInfo();
    return 0;
    // Изход: "Brand: Toyota, Year: 2020"
}

