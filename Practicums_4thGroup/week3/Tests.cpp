#include <iostream>
#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    string brand;
    double speed;

public:
    Car(string b, double s) {
        brand = b;
        speed = s;
    }

    void accelerate(double amount) {
        speed += amount;
        cout << brand << " accelerates to " << speed << " km/h\n";
    }

    void brake(double amount) {
        speed -= amount;
        if (speed < 0) speed = 0;
        cout << brand << " brakes to " << speed << " km/h\n";
    }

    void showInfo() {
        cout << "Brand: " << brand << ", Speed: " << speed << " km/h\n";
    }
};

int main() {
    Car myCar("Toyota", 50);

    myCar.showInfo();      
    myCar.accelerate(20); 
    myCar.brake(30);      
}

