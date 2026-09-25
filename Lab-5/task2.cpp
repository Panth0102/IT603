#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Box{
    int length;
public:
    Box(int l) {
        length = l;
        cout << "Constructor called" << endl;
    }
    Box(const Box& b) {
        length = b.length;
        cout << "Copy Constructor called" << endl;
    }
    void display() {
        cout << "Length = " << length << endl;
    }
    ~Box() {
        cout << "Destructor called" << endl;
    }
};

void show(Box b) {
    b.display();
}

int main() {
    int length;
    cin >> length;
    Box b(length);
    show(b);

    return 0;
}
