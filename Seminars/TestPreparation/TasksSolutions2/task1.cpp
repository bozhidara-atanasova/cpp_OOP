#include <iostream>
#include <iomanip>
#pragma warning(disable:4996)
class Employee
{
private:
    char* name;
    char* possition;
    double salary;
    int ID;
public:
    const char* getName() const
    {
        return name;
    }
    double getSalary() const
    {
        return salary;
    }
    Employee() { //default constructor
        name = new char[1];
        name[0] = '\0';

        possition = new char[1];
        possition[0] = '\0';

        salary = 0;
        ID = 0;
    }
    //constructor
    Employee(const char* n, const char* p, double s, int i)
    {
        name = new char[strlen(n) + 1];
        strcpy(name, n);

        possition = new char[strlen(p) + 1];
        strcpy(possition, p);

        salary = s;
        ID = i;
    }
    //copy constructor
    Employee(const Employee& other)
    {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);

        possition = new char[strlen(other.possition) + 1];
        strcpy(possition, other.possition);

        salary = other.salary;
        ID = other.ID;
    }
    //operator = 
    Employee& operator=(const Employee& other)
    {
        if (this != &other)
        {
            delete[] name;
            delete[] possition;

            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);

            possition = new char[strlen(other.possition) + 1];
            strcpy(possition, other.possition);

            salary = other.salary;
            ID = other.ID;
        }
        return *this;
    }
    ~Employee()
    {
        delete[] name;
        delete[] possition;
    }
    char* getInitials() const {
        char* initials = new char[10];
        int j = 0;

        if (isalpha(name[0])) {
            initials[j++] = name[0];
        }

        for (int i = 1; name[i] != '\0'; i++) {
            if (name[i - 1] == ' ' && isalpha(name[i])) {
                initials[j++] = name[i];
            }
        }

        initials[j] = '\0';
        return initials;
    }
    bool operator==(const Employee& other) const
    {
        return strcmp(possition, other.possition) == 0;
    }
    void print() const {
        std::cout << "Name: " << name << "\n";
        std::cout << "Possition: " << possition << "\n";
        std::cout << "Salary: " << salary << "\n";
        std::cout << "ID: " << ID << "\n";
    }

};
class Company
{
private:
    Employee* employees;
    int capacity;
    int size;
public:
    
    Company(int n)
    {
        capacity = n;
        size = 0;
        employees = new Employee[capacity];
    }
    ~Company(){
        delete[] employees;
    }
    bool exists(const Employee& e)const
    {
        for (int i = 0; i < size; i++)
        {
            if (strcmp(employees[i].getName(), e.getName()) == 0)
                return true;
        }
        return false;
    }
    void addEmployee(const Employee& e) {
        if (size >= capacity) {
            std::cout << "There is no space for more employees.\n";
            return;
        }
        if (exists(e)) {
            std::cout << "The employee already exists.\n";
            return;
        }
        employees[size++] = e;
    }

    Company& operator+=(const Employee& e) {
        addEmployee(e);
        return *this;
    }

    void removeEmployee(const char* name) {
        for (int i = 0; i < size; ++i) {
            if (strcmp(employees[i].getName(), name) == 0) {
                for (int j = i; j < size - 1; ++j) {
                    employees[j] = employees[j + 1];
                }
                size--;
                std::cout << "The employee: \"" << name << "\" is removed.\n";
                return;
            }
        }
        std::cout << "The employee \"" << name << "\" is not found.\n";
    }

    double totalSalaries() const {
        double sum = 0;
        for (int i = 0; i < size; ++i)
            sum += employees[i].getSalary();
        return sum;
    }

    void print() const {
        std::cout << std::left << std::setw(20) << "Name"
            << std::setw(15) << "Position"
            << std::setw(10) << "Salary"
            << std::setw(12) << "ID" << "\n";
        std::cout << std::string(60, '-') << "\n";
        for (int i = 0; i < size; ++i)
            employees[i].print();
    }

    void merge(const Company& other) {
        for (int i = 0; i < other.size && size < capacity; ++i) {
            if (!exists(other.employees[i])) {
                employees[size++] = other.employees[i];
            }
        }
    }

    Employee findHighestPaid() const {
        if (size == 0) std::cout << "There are no employees";
        int maxIndex = 0;
        for (int i = 1; i < size; ++i) {
            if (employees[i].getSalary() > employees[maxIndex].getSalary())
                maxIndex = i;
        }
        return employees[maxIndex];
    }
};
int main()
{
    Employee a("Ivan Petrov", "Developer", 3000, 1234567890);
    Employee b("Maria Ivanova", "Developer", 3200, 9876543210);

    a.print();

    char* initials = a.getInitials();
    std::cout << "The initials of A: " << initials << "\n";
    delete[] initials;

    if (a == b) {
        std::cout << "The employees are on the same possition.\n";
    }
    else {
        std::cout << "The employees are on diffrent possitions.\n";
    }

    return 0;
}

