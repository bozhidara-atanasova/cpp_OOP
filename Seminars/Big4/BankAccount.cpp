#include <iostream>
#pragma warning(disable:4996)
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
class BankAccount
{
private:
    MyString iban;
    double balance;
    MyString name;
public:
    BankAccount(MyString i, double b, MyString n) : iban(i), balance(b), name(n) {}
    BankAccount(const BankAccount& other) : iban(other.iban), balance(other.balance), name(other.name) {}

    BankAccount& operator=(const BankAccount& other)
    {
        if (this != &other)
        {
            iban = other.iban;
            balance = other.balance;
            name = other.name;
        }
        return *this;
    }
    ~BankAccount() {}
    double deposit(double amount)
    {
        return balance = balance + amount;
    }
    double withdraw(double amount)
    {
        return balance = balance - amount;
    }
    void print()
    {
        std::cout << "The holder iban is : " << iban << std::endl <<
            " and the balance is: "<<balance << std::endl <<
            "and the name of the holder is: " << name << std::endl;
    }
};
int main()
{
    BankAccount acc1("BG123456", 500.0, "John Doe");
    acc1.deposit(200);
    acc1.withdraw(100);
    BankAccount acc2 = acc1; // Тества копиконструктора
    acc2.print();
}

