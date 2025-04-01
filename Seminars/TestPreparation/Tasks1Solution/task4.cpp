#include <iostream>
#pragma warning(disable:4996)
class Student
{
private:
    char* name;
    float grade;
public:
    Student(const char* n = "", float g = 2.00)
    {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        grade = g;
    }
    Student(const Student& other)
    {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        grade = other.grade;
    }
    Student& operator=(const Student& other)
    {
        if (this != &other)
        {
            delete[] name;
            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);
            grade = other.grade;
        }
        return *this;
    }
    const char* getName() const {
        return name;
    }

    float getGrade() const {
        return grade;
    }
    ~Student()
    {
        delete[] name;
    }
};
class Classroom
{
private:
    Student* students;
    int size;
    int capacity;
    void resize()
    {
        capacity *= 2;
        Student* newArr = new Student[capacity];
        for (int i = 0; i < size; i++)
        {
            newArr[i] = students[i];
        }delete[] students;
        students = newArr;
    }
public:
    Classroom(int cap = 4) {
        capacity = cap;
        size = 0;
        students = new Student[capacity];
    }
    ~Classroom()
    {
        delete[] students;
    }
    void addStudent(const Student& s)
    {
        if (size >= capacity)
        {
            resize();
        }
        students[size++] = s;
    }
    float averageGrade() const
    {
        if (size == 0)return 0;
        float sum = 0;
        for (int i = 0; i < size; i++)
        {
            sum += students[i].getGrade();
        }return sum / size;
    }
    void removeStudent(const char* nameToRemove) {
        for (int i = 0; i < size; ++i) {
            if (strcmp(students[i].getName(), nameToRemove) == 0) {
                for (int j = i; j < size - 1; ++j)
                    students[j] = students[j + 1];
                --size;
                break;
            }
        }
    }
    void merge(const Classroom& c) {
        for (int i = 0; i < c.size; ++i)
            addStudent(c.students[i]);
    }

    void print() const {
        for (int i = 0; i < size; ++i)
            std::cout << students[i].getName() << ": " << students[i].getGrade() << std::endl;
    }
};
int main()
{
    Classroom a;
    a.addStudent(Student("Ivan", 5.0));
    a.addStudent(Student("Maria", 6.0));

    Classroom b;
    b.addStudent(Student("Georgi", 4.5));

    a.merge(b);

    std::cout << "Students in class A:" << std::endl;
    a.print();

    std::cout << "Average grade: " << a.averageGrade() << std::endl;

    a.removeStudent("Maria");
    std::cout << "After removing Maria:" << std::endl;
    a.print();

    return 0;
}
