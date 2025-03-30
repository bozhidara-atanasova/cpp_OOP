#include <iostream>

void modifyArray(int* array, int size) {
    for (int i = 0; i < size; ++i) {
        array[i] += i;
    }
}

int main() {
    int array[] = { 10, 20, 30, 40, 50 };
    int size = sizeof(array) / sizeof(array[0]);

    modifyArray(array, size);

    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }

    return 0;
}