#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

// 1. STRUCT 
struct Engine {
    int horsePower;
    string fuelType;
};

enum CarType { SEDAN, SUV, TRUCK };

struct Car {
    string brand;
    int year;
    double price;
    Engine engine;
    CarType type;
};

//3
void printCarInfo(const Car& car) {
    cout << "Brand: " << car.brand << ", Year: " << car.year
        << ", Price: " << car.price << ", Engine: " << car.engine.horsePower
        << " HP, Fuel: " << car.engine.fuelType;

    cout << ", Type: ";
    switch (car.type) {
    case SEDAN: cout << "SEDAN"; break;
    case SUV: cout << "SUV"; break;
    case TRUCK: cout << "TRUCK"; break;
    }
    cout << endl;
}

// 2. ENUM 
enum Day { Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday };

bool isWeekend(Day d) {
    return d == Saturday || d == Sunday;
}

// 3. UNION
union Data {
    int intValue;
    char str[20];
};

struct Value {
    bool isFloat;
    union {
        float f;
        int i;
    } val;
};

// 4. TYPEDEF и USING
typedef unsigned int uint;
using LongMap = std::pair<std::string, std::vector<int>>;

// 5. NAMESPACE
namespace MathOperations {
    int add(int a, int b) { return a + b; }
    int sub(int a, int b) { return a - b; }
    int mul(int a, int b) { return a * b; }
}

namespace FastMath {
    int add(int a, int b) { return a + b + 1; } 
    int sub(int a, int b) { return a - b - 1; }
    int mul(int a, int b) { return a * b + 10; }
}

int main() {
    Car cars[5];
    for (int i = 0; i < 5; ++i) {
        int type;
        cout << "Въведи brand, year, price, engine HP, fuel type, и тип (0=SEDAN,1=SUV,2=TRUCK):\n";
        cin >> cars[i].brand >> cars[i].year >> cars[i].price >> cars[i].engine.horsePower >> cars[i].engine.fuelType >> type;
        cars[i].type = static_cast<CarType>(type);
    }

    for (int i = 0; i < 5; ++i) {
        printCarInfo(cars[i]);
    }


    Day today = Saturday;
    cout << "Is weekend? " << (isWeekend(today) ? "Yes" : "No") << endl;

    Data d;
    d.intValue = 123;
    cout << "int: " << d.intValue << endl;
    strcpy(d.str, "hello");
    cout << "str: " << d.str << endl;

  
    Value v;
    v.isFloat = true;
    v.val.f = 5.67f;
    if (v.isFloat) cout << "Float value: " << v.val.f << endl;
    else cout << "Int value: " << v.val.i << endl;


    uint u = 42;
    cout << "uint u = " << u << endl;

    LongMap entry = { "data", {1, 2, 3} };
    cout << "LongMap: " << entry.first << " -> size: " << entry.second.size() << endl;

   
    using namespace MathOperations;
    cout << "Add: " << add(3, 4) << ", Mul: " << mul(2, 5) << endl;


    cout << "FastMath::add: " << FastMath::add(3, 4) << endl;

    return 0;
}
