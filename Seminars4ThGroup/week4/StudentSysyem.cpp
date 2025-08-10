#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
class Student {
private:
    std::string name;
    std::string facultyNumber;
    double grades[10];
    int gradesCount;
    double averageGrade;

    void recalcAverage() {
        if (gradesCount == 0) { averageGrade = 0.0; return; }
        double sum = 0.0;
        for (int i = 0; i < gradesCount; ++i) sum += grades[i];
        averageGrade = sum / gradesCount;
    }

public:

    Student(const std::string& n = "", const std::string& fn = "")
        : name(n), facultyNumber(fn), gradesCount(0), averageGrade(0.0) {
    }

    bool addGrade(double grade) {
        if (gradesCount >= 10) return false;                 
        if (grade < 2.0 || grade > 6.0) return false;       
        grades[gradesCount++] = grade;
        recalcAverage();
        return true;
    }

    double getAverageGrade() const { return averageGrade; }

    std::string getInfo() const {
        std::ostringstream oss;
        oss << "Name: " << name
            << ", FN: " << facultyNumber
            << ", Grades: " << gradesCount
            << ", Avg: " << std::fixed << std::setprecision(2) << averageGrade;
        return oss.str();
    }

    
    const std::string& getName() const { return name; }
    const std::string& getFacultyNumber() const { return facultyNumber; }
};
class Course {
private:
    std::string courseName;
    std::string teacher;
    Student students[30];
    int studentsCount;

    int findIndexByFN(const std::string& fn) const {
        for (int i = 0; i < studentsCount; ++i) {
            if (students[i].getFacultyNumber() == fn) return i;
        }
        return -1;
    }

public:
  
    Course(const std::string& name = "", const std::string& t = "")
        : courseName(name), teacher(t), studentsCount(0) {
    }

    bool addStudent(const Student& student) {
        if (studentsCount >= 30) return false;
        if (findIndexByFN(student.getFacultyNumber()) != -1) return false;
        students[studentsCount++] = student;
        return true;
    }

    bool removeStudent(const std::string& facultyNumber) {
        int idx = findIndexByFN(facultyNumber);
        if (idx == -1) return false;
        for (int i = idx; i < studentsCount - 1; ++i) {
            students[i] = students[i + 1];
        }
        --studentsCount;
        return true;
    }
    const Student* getTopStudent() const {
        if (studentsCount == 0) return nullptr;
        int bestIdx = 0;
        for (int i = 1; i < studentsCount; ++i) {
            if (students[i].getAverageGrade() > students[bestIdx].getAverageGrade()) {
                bestIdx = i;
            }
        }
        return &students[bestIdx];
    }

    void printAllStudents() const {
        std::cout << "Course: " << courseName << " | Teacher: " << teacher << "\n";
        if (studentsCount == 0) {
            std::cout << "(no students)\n";
            return;
        }
        for (int i = 0; i < studentsCount; ++i) {
            std::cout << i + 1 << ". " << students[i].getInfo() << "\n";
        }
    }
};
int main()
{
    Student s1("Ivan Ivanov", "FN12345");
    s1.addGrade(5.50);
    s1.addGrade(6.00);
    s1.addGrade(5.00);

    Student s2("Maria Petrova", "FN54321");
    s2.addGrade(4.50);
    s2.addGrade(5.00);

    Student s3("Georgi Georgiev", "FN11111");
    s3.addGrade(6.00);
    s3.addGrade(6.00);
    s3.addGrade(5.75);

    Course oop("Object-Oriented Programming", "Assoc. Prof. Petrov");
    oop.addStudent(s1);
    oop.addStudent(s2);
    oop.addStudent(s3);

    oop.printAllStudents();
    std::cout << "-----------------------------\n";

    if (const Student* top = oop.getTopStudent()) {
        std::cout << "Top student: " << top->getInfo() << "\n";
    }

    std::cout << "-----------------------------\n";
    oop.removeStudent("FN54321");
    oop.printAllStudents();

    return 0;
}

