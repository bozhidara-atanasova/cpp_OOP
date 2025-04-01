#include <iostream>
#include <iomanip>
#pragma warning(disable:4996)
class Product
{
private:
    char* name;
    char* category;
    double price;
public:
    const char* getName() const
    {
        return name;
    }
    const char* getCategory() const
    {
        return category;
    }
    double getPrice() const
    {
        return price;
    }
    Product() //default constructor
    {
        name = new char[1];
        name[0] = '\0';

        category = new char[1];
        category[0] = '\0';

        price = 0.0;
    }
    Product(const char* n, const char* c, double p) //constructor with parameters
    {
        name = new char[strlen(n) + 1];
        strcpy(name, n);

        category = new char[strlen(c) + 1];
        strcpy(category, c);

        price = p;
    }
    //copy constructor
    Product(const Product& other)
    {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);

        category = new char[strlen(other.category) + 1];
        strcpy(category, other.category);

        price = other.price;
    }
    //operator=
    Product& operator=(const Product& other)
    {
        if (this != &other)
        {     
            delete[] name;
            delete[] category;

            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);

            category = new char[strlen(other.category) + 1];
            strcpy(category, other.category);

            price = other.price;
        }
        return *this;
    }
    void print() const {
        std::cout << std::left << std::setw(20) << name
            << std::setw(20) << category
            << std::setw(10) << price << "\n";
    }
    ~Product() //destructor
    {
        delete[] name;
        delete[] category;
    }
    bool operator<(const Product& other) const //operator <
    {
        return price < other.price;
    }
    void applyDiscount(double percent)
    {
        if (percent < 0 || percent > 100)
        {
            std::cout << "Invalid discount";
            return;
        }
        price -= price * (percent / 100.0);
    }
};
class Store
{
private:
    Product* products;
    int size;
    int capacity;
public:
    Store(int cap)
    {
        capacity = cap;
        size = 0;
        products = new Product[capacity];
    }
    ~Store()
    {
        delete[] products;
    }
    bool exist(const Product& p) const
    {
        for (int i = 0; i < size; i++)
        {
            if(strcmp(products[i].getName(), p.getName()) ==0)
                return true;
        }
        return false;
    }
    void addProduct(const Product& p)
    {
        if (size >= capacity)
        {
            std::cout << "Store is full";
            return;
        }
        if (exist(p))
        {
            std::cout << "Product already exists";
            return;
        }
        products[size++] = p;
    }
    Store& operator+=(const Product& p) {
        addProduct(p);
        return *this;
    }
    void removeProduct(const char* name) {
        for (int i = 0; i < size; ++i) {
            if (strcmp(products[i].getName(), name) == 0) {
                for (int j = i; j < size - 1; ++j) {
                    products[j] = products[j + 1];
                }
                size--;
                std::cout << "Product \"" << name << "\" removed.\n";
                return;
            }
        }
        std::cout << "Product \"" << name << "\" not found.\n";
    }
    double totalCost() const {
        double sum = 0;
        for (int i = 0; i < size; ++i) {
            sum += products[i].getPrice();
        }
        return sum;
    }

    void print() const {
        std::cout << std::left << std::setw(20) << "Name"
            << std::setw(20) << "Category"
            << std::setw(10) << "Price" << "\n";
        std::cout << std::string(50, '-') << "\n";

        for (int i = 0; i < size; ++i) {
            std::cout << std::left << std::setw(20) << products[i].getName()
                << std::setw(20) << products[i].getCategory()
                << std::setw(10) << products[i].getPrice() << "\n";
        }
    }

    void merge(const Store& other) {
        for (int i = 0; i < other.size && size < capacity; ++i) {
            if (!exist(other.products[i])) {
                products[size++] = other.products[i];
            }
        }
    }

    Product findMostExpensive() const {
        if (size == 0) {
            throw std::runtime_error("Store is empty!");
        }
        int maxIndex = 0;
        for (int i = 1; i < size; ++i) {
            if (products[i].getPrice() > products[maxIndex].getPrice())
                maxIndex = i;
        }
        return products[maxIndex];
    }
};
int main()
{

    return 0;
}

