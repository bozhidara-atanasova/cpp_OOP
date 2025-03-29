#include <iostream>
#include <cstring>
#pragma warning(disable : 4996)
using namespace std;

union Data {
    int number;
    char text[20];
};
union Number {
    int i;
    float f;
};

struct Value {
    char type; // 'i' for int, 'f' for float
    Number data;
};

void printValue(Value v) {
    if (v.type == 'i') {
        cout << "Integer: " << v.data.i << endl;
    }
    else if (v.type == 'f') {
        cout << "Float: " << v.data.f << endl;
    }
    else {
        cout << "Unknown type!" << endl;
    }
}
int main() {
    Data d;

    // Store integer
    d.number = 123;
    cout << "Number: " << d.number << endl;

    // Overwrite with text

    strcpy(d.text, "Example");


    cout << "Text: " << d.text << endl;
    cout << "Number after text: " << d.number << " (invalid)" << endl;
    Value v1;
    v1.type = 'i';
    v1.data.i = 42;

    Value v2;
    v2.type = 'f';
    v2.data.f = 3.14f;

    printValue(v1);
    printValue(v2);

    return 0;

    return 0;
}
