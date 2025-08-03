#include <iostream>
struct Task
{
    char name[50];
    enum Dificculty
    {
        Easy,
        Medium,
        Hard
    } difficulty;
    enum Priority
    {
        Wait,
        Emergency
    } priority;
};
void read(Task& t) 
{
    int d, p;
    std::cin >> t.name >> d >> p;
    t.difficulty = static_cast<Task::Dificculty>(d);
    t.priority = static_cast<Task::Priority>(p);
}
void print(const Task& t)
{
    std::cout << "Name: " << t.name << std::endl;

    std::cout << "Difficulty: ";
    switch (t.difficulty)
    {
    case Task::Easy:
        std::cout << "Easy";
        break;
    case Task::Medium:
        std::cout << "Medium";
        break;
    case Task::Hard:
        std::cout << "Hard";
        break;
    }
    std::cout << std::endl;

    std::cout << "Priority: ";
    switch (t.priority)
    {
    case Task::Wait:
        std::cout << "Wait";
        break;
    case Task::Emergency:
        std::cout << "Emergency";
        break;
    }
    std::cout << std::endl;
}
int main()
{
    Task t;
    std::cout << "Enter name, difficulty (0-Easy,1-Medium,2-Hard) and priority (0-Wait,1-Emergency):\n";
    read(t);
    print(t);
    return 0;
}
