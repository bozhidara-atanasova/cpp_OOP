#include <iostream>
using namespace std;

enum Day {
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
};
enum CarType {
    SEDAN,
    SUV,
    TRUCK
};

struct Car {
    string brand;
    int year;
    double price;
    CarType type;
};

bool isWeekend(Day day) {
    return (day == SATURDAY || day == SUNDAY);
}

void printDayType(Day day) {
    if (isWeekend(day)) {
        cout << "It's a weekend." << endl;
    }
    else {
        cout << "It's a weekday." << endl;
    }
}
void printCar(const Car& car) {
    cout << "Brand: " << car.brand << endl;
    cout << "Year: " << car.year << endl;
    cout << "Price: $" << car.price << endl;

    cout << "Type: ";
    switch (car.type) {
    case SEDAN: cout << "Sedan"; break;
    case SUV: cout << "SUV"; break;
    case TRUCK: cout << "Truck"; break;
    default: cout << "Unknown";
    }
    cout << endl << "-------------------" << endl;
}

int main() {
    Day today = FRIDAY;
    printDayType(today);

    today = SUNDAY;
    printDayType(today);

    Car c1 = { "Toyota", 2022, 28000.0, SUV };
    Car c2 = { "Ford", 2020, 35000.0, TRUCK };

    printCar(c1);
    printCar(c2);

    return 0;
}
