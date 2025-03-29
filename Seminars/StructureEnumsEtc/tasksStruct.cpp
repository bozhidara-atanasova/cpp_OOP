#include <iostream>
struct Car
{
    std::string brand;
    int year;
    double price;
    Engine engine;
};
struct Engine {
    int horsePower;
    std::string fuelType;
};
void print(const Car& c) {
    std::cout << "Brand: " << c.brand << std::endl;
    std::cout << "Year: " << c.year << std::endl;
    std::cout << "Price: " << c.price << " lv." << std::endl;
    std::cout << "Engine horse power: " << c.engine.horsePower << std::endl;
    std::cout << "Fuel type: " << c.engine.fuelType << std::endl;
    std::cout << "----------------------------" << std::endl;
}
int main()
{
    const int number = 2;
    Car cars[number];

    for (int i = 0; i < number; i++) {
        std::cout << "Enter brand: ";
        std:: cin >> cars[i].brand;

        std::cout << "Enter year: ";
        std::cin >> cars[i].year;

        std::cout << "Enter price: ";
        std::cin >> cars[i].price;

        std::cout << "Enter engine horse power: ";
        std::cin >> cars[i].engine.horsePower;

        std::cout << "Enter fuel type: ";
        std::cin >> cars[i].engine.fuelType;

        std::cout << std::endl;
    }

    std::cout << "\nList with cars:\n";
    for (int i = 0; i < number; i++) {
        print(cars[i]);
    }

    return 0;
    
}

