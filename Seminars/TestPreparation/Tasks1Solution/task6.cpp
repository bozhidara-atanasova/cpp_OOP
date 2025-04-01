#include <iostream>
#pragma warning(disable:4996)
const int MAX_TITLE_LENGTH = 50;
class Movie
{
private:
    char title[MAX_TITLE_LENGTH + 1];
    int duration;
public:
    Movie(const char* t = "", int d = 0) : duration(d)
    {
        strncpy(title, t, MAX_TITLE_LENGTH);
        title[MAX_TITLE_LENGTH] = '\0';
    }
    Movie(const Movie& other) {
        strncpy(title, other.title, MAX_TITLE_LENGTH);
        title[MAX_TITLE_LENGTH] = '\0';
        duration = other.duration;
    }
    Movie& operator=(const Movie& other) {
        if (this != &other) {
            strncpy(title, other.title, MAX_TITLE_LENGTH);
            title[MAX_TITLE_LENGTH] = '\0';
            duration = other.duration;
        }
        return *this;
    }
    bool compareByDuration(const Movie& m) const
    {
        return duration > m.duration;
    }
    friend std::ostream& operator<<(std::ostream& os, const Movie& m) {
        os << "Title: " << m.title << ", Duration: " << m.duration << " min";
        return os;
    }
    ~Movie() {}
};
int main()
{
    Movie m1("Inception", 148);
    Movie m2("Titanic", 195);

    std::cout << m1 << std::endl;
    std::cout << m2 << std::endl;

    if (m2.compareByDuration(m1))
        std::cout << "Titanic is longer than Inception." << std::endl;
    else
        std::cout << "Inception is longer or equal to Titanic." << std::endl;

    return 0;
}

