#include <iostream>
#pragma warning(disable:4996)
class DynamicArray
{
private:
    int* data;
    size_t size;
    size_t capacity;

    void resize() {
        capacity = capacity == 0 ? 1 : capacity * 2;
        int* newData = new int[capacity];
        for (size_t i = 0; i < size; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }
public:
    DynamicArray() : data(nullptr), size(0) , capacity(0) {}

    DynamicArray(size_t initialCapacity) : size(0), capacity(initialCapacity) {
        data = new int[capacity];
    }


    DynamicArray(const DynamicArray& other) : size(other.size), capacity(other.capacity) {
        data = new int[capacity];
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    DynamicArray& operator=(const DynamicArray& other) {
        if (this != &other) {
            delete[] data;

            size = other.size;
            capacity = other.capacity;
            data = new int[capacity];
            for (size_t i = 0; i < size; ++i) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }


    ~DynamicArray() {
        delete[] data;
    }

    void push(int value) {
        if (size >= capacity) {
            resize();
        }
        data[size++] = value;
    }


    void print() const {
        for (size_t i = 0; i < size; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};
int main()
{
    DynamicArray arr(5);
    arr.push(1);
    arr.push(2);
    arr.push(3);
    arr.print(); // Expected output: 1 2 3
}

