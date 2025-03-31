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
class Book
{
private:
    MyString title;
    MyString author;
public:
    Book(MyString t, MyString a) : title(t),author(a) {} //parametric constructor
    Book() { std::cout << "Default constructor"; } // default constructor
    Book(const Book& other) : title (other.title) , author (other.author) {} //copy constructor

    Book& operator=(const Book& other) // operator =
    {
        if (this != &other)
        {
            title = other.title;
            author = other.author;
        }
        return *this;
    }
    ~Book() {} // destructor
    void print()
    {
        std::cout << "The title is " << title << "and the author is" << author<<std::endl;
    }
};
class Library : Book
{
private:
    Book* books;
    size_t bookCount;
public:
    Library() : books(nullptr), bookCount(0) {}
    Library(const Library& other) : bookCount(other.bookCount)
    {
        if (bookCount > 0) {
            books = new Book[bookCount];
            for (size_t i = 0; i < bookCount; ++i) {
                books[i] = other.books[i]; 
            }
        }
        else {
            books = nullptr;
        }
    }
    Library& operator=(const Library& other)
    {
        if (this != &other) {
            delete[] books;
            bookCount = other.bookCount;
            books = new Book[bookCount];
            for (size_t i = 0; i < bookCount; ++i) {
                books[i] = other.books[i];
            }
        }
        return *this;
    }
    ~Library() {
        delete[] books;
    }

    void addBook(const Book& newBook) {
        Book* newArray = new Book[bookCount + 1];
        for (size_t i = 0; i < bookCount; ++i) {
            newArray[i] = books[i];
        }
        newArray[bookCount] = newBook;

        delete[] books;
        books = newArray;
        ++bookCount;
    }

    void printBooks() const {
        if (bookCount == 0) {
            std::cout << "Library is empty.\n";
            return;
        }

        std::cout << "Library contains " << bookCount << " book(s):\n";
        for (size_t i = 0; i < bookCount; ++i) {
            std::cout << i + 1 << ". ";
            books[i].print();
        }
    }
};
int main()
{
    Book b1("1984", "George Orwell");
    Book b2("Brave New World", "Aldous Huxley");
    Library lib;
    lib.addBook(b1);
    lib.addBook(b2);
    lib.printBooks();
}

