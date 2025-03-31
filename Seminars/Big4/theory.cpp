#include <iostream>
class Example {
private:
    int value;
    int* data;

public:
    Example() {
        std::cout << "Default constructor called\n";
        value = 0;
        data = new int(0);
    }
    Example(int v) {
        std::cout << "Parameterized constructor called\n";
        value = v;
        data = new int(v);
    }

    Example(int v, bool useInitList) : value(v) {
        std::cout << "Constructor with initializer list called\n";
        data = new int(v);
    }

    Example(const Example& other) {
        std::cout << "Copy constructor called\n";
        value = other.value;
        data = new int(*other.data); 
    }

    void show() const {
        std::cout << "Value = " << value << "\n";
    }
    ~Example()
    {
        delete[] data;
        std::cout << "Object destroyes!" << std::endl;
    }
    Example& operator= (const Example& other)
    {
        if (this != &other)
        {
            delete data;
            data = new int(*other.data);
        }
        return *this;
    }
};
//when we use dynamic memory, we should always define - constructor,destructor,copy constructor, operator=

int main()
{
    std::cout << "Hello World!\n";
}

