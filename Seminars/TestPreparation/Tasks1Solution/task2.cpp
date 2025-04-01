#include <iostream>
#include <cstring> 
#pragma warning(disable : 4996)

class Car {
private:
    char* brand;
    int year;

public:
    Car() {
        brand = new char[1];
        brand[0] = '\0';
        year = 0;
    }

    Car(const char* b, int y) {
        brand = new char[strlen(b) + 1];
        strcpy(brand, b);
        year = y;
    }

    Car(const Car& other) {
        brand = new char[strlen(other.brand) + 1];
        strcpy(brand, other.brand);
        year = other.year;
    }

    Car& operator=(const Car& other) {
        if (this != &other) {
            delete[] brand; 

            brand = new char[strlen(other.brand) + 1];
            strcpy(brand, other.brand);
            year = other.year;
        }
        return *this;
    }

    ~Car() {
        delete[] brand;
    }

    void print() const {
        std::cout << "Brand: " << brand << ", Year: " << year << std::endl;
    }
};
int main()
{
    Car car1("Toyota", 2015);
    Car car2 = car1; 

    Car car3;
    car3 = car1;    

    car1.print();
    car2.print();
    car3.print();

    return 0;
}

