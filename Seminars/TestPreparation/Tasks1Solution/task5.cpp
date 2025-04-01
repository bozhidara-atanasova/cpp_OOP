#include <iostream>
#pragma warning(disable:4996)
const int MAX_TITLE_LENGTH = 50;
const int MAX_AUTHOR_LENGTH = 30;
class Book
{
private:
    char title[MAX_TITLE_LENGTH + 1];
    char author[MAX_AUTHOR_LENGTH + 1];
public:
    Book(const char* t = "", const char* a = "")
    {
        title[MAX_TITLE_LENGTH] = '\0'; 
        strncpy(author, a, MAX_AUTHOR_LENGTH);

        author[MAX_AUTHOR_LENGTH] = '\0';
        strncpy(title, t, MAX_TITLE_LENGTH);
    }
    const char* getAuthor() const { return author; }
    const char* getTitle() const { return title; }
    void print() const {
        std::cout << "Title: " << title << ", Author: " << author << std::endl;
    }
   
};
class Library
{
private:
    Book* books;
    int size;
    int capacity;
    void resize()
    {
        capacity *= 2;
        Book* newBooks = new Book[capacity];
        for (int i = 0; i < size; i++)
        {
            newBooks[i] = books[i];
        }
        delete[] books;
        books = newBooks;
    }
public:
    Library(int cap = 4)
    {
        size = 0;
        capacity = cap;
        books = new Book[capacity];
    }
    ~Library()
    {
        delete[] books;
    }
    Library& operator= (const Library& other)
    {
        if (this != &other)
        {
            delete[] books;
            size = other.size;
            capacity = other.capacity;
            books = new Book[capacity];
            for (int i = 0; i < size; i++)
            {
                books[i] = other.books[i];
            }
        }
        return *this;
    }
    Library& operator+=(const Book& b)
    {
        if (size >= capacity)resize();
        books[size++] = b;
        return *this;
    }
    const Book* findBookByAuthor(const char* author) const {
        for (int i = 0; i < size; ++i) {
            if (strcmp(books[i].getAuthor(), author) == 0)
                return &books[i];
        }
        return nullptr;
    }
    void print() const
    {
        for (int i = 0; i < size; i++)
        {
            books[i].print();
        }
    }
};
int main()
{
    Library lib;
    lib += Book("Pod igoto", "Ivan Vazov");
    lib += Book("Bai Ganyo", "Alekо Konstantinov");
    lib += Book("Chichovtsi", "Ivan Vazov");

    lib.print();

    const Book* found = lib.findBookByAuthor("Ivan Vazov");
    if (found)
        std::cout << "First book by Ivan Vazov: " << found->getTitle() << std::endl;
    else
        std::cout << "No book by that author found.\n";

    return 0;
}

