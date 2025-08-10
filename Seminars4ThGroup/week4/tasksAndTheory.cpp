#include <iostream>
#include <string>
//task1
class Person {
private:
    std::string name;
    int age;
public:
    Person(std::string n, int a)
    {
        name = n;
        age = a;
    }
    std::string getName()
    {
        return name;
    }
    int getAge()
    {
        return age;
    }
    void setName(std::string n) {
        name = n;
    }

    void setAge(int a) {
        if (a >= 0) {
            age = a;
        }
    }

    void introduce() {
       std::cout<< "Hello, my name is " + name + " and I am " + std::to_string(age) + " years old.";
    }
};
//task2
class BankAccount
{
private:
    std::string owner;
    double balance;
public:
    BankAccount(std::string o, double b)
    {
        owner = o;
        balance = b;
    }
    void deposit(double amaount)
    {
        balance += amaount;
    }
   void withdraw(double amount)
    {
        balance -= amount;
    }
    double getBalance()
    {
        return balance;
    }
    void setBalance(int b)
    {
        if (balance < 0)std::cout << "Not enough money";
    }
};
//task3
class Student
{
private:
    std::string name;
    int age;
    std::string facultyNumber;
public:
    Student(std::string n, int a, std::string fn)
    {
        name = n;
        age = a;
        facultyNumber = fn;
    }
    std::string getFacultyNumber()
    {
        return facultyNumber;
    }
    void introduce()
    {
        std::cout << "Hello, my name is " + name + " and I am " + std::to_string(age) + " years old. And my FN is: " +facultyNumber ;
    }
};

int main()
{
    //task1
    Person p("Ivan", 25);
    p.introduce();
    std::cout << std::endl;
    //task2
    BankAccount acc("Maria", 1000);
    acc.deposit(500);
    acc.withdraw(200);
    std::cout << acc.getBalance();
    std::cout << std::endl;
    //Exit: 1300
    //task3
    Student s("Anna", 20, "F12345");
    s.introduce();
}

