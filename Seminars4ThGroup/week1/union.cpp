#include <iostream>

union Data
{
    int i;
    float f;
    char str[20];
};

int main()
{
    Data data;
    data.i = 10;
    std::cout << "data.i: " << data.i << std::endl;
    data.f = 220.5;
    std::cout << "data.f: " << data.f << std::endl;
    return 0;
}

