#include <iostream>
class Person
{
private:
    std::string name;
    int age;
public:
    Person(const std::string n, int a) : name(n), age(a) {}
    std::string getName() const
    {
        return name;
    }
    int getAge() const
    {
        return age;
    }
    void setAge(int newAge)
    {
        if (newAge >= 0)
        {
            age = newAge;
        }
    }
    void introduce() const
    {
        std::cout << "Hello, my name is " << name << " and I am " << age << " years old";
    }

};
class BankAccount
{
private:
    std::string owner;
    double balance;
public:
    BankAccount(const std::string o, double b) : owner(o), balance(b) {}
    double deposit(double amount)
    {
        return balance = balance + amount;
    }
    double withdraw(double amount)
    {
        if (balance > amount)
            return balance -= amount;
        else {
            std::cout << "Not enough money";
            return balance;
        }
    }
    double getBalance() const
    {
        return balance;
    }
};
class Student : public Person
{
private:
    std::string facultyNumber;
public:
    Student(const std::string& name, int age, const std::string& fn) : Person(name, age), facultyNumber(fn) {}
    std::string getFacultyNumber() const {
        return facultyNumber;
    }

    void introduce() const  {
        Person::introduce();
        std::cout << " My FN is " << facultyNumber << ".";
    }
};
int main()
{
    Person p("Ivan", 25);
    p.introduce();
    //Exit: "Hello, my name is Ivan and I am 25 years old."
    std::cout << std::endl;
    BankAccount acc("Maria", 1000);
    acc.deposit(500);
    acc.withdraw(200);
    std::cout << acc.getBalance();
    std::cout << std::endl;
    // Exit: 1300
    Student s("Anna", 20, "F12345");
    s.introduce();
    // Exit: "Hello! My name is Anna and I am 20 years old. My FN is F12345."
}

