#include <iostream>
using namespace std;

class Array {
public:
    int* value;

    Array(int val) {
        value = new int(val);
    }

    Array(const Array &a) {
        value = a.value;
    }

    int getValue() {
        return *value;
    }

    void setValue(int val) {
        *value = val;
    }

};

int main() {
    int n, n2;
    cin >> n >> n2;

    Array a1(n);
    Array a2(a1);

    cout << "Original value: " << a1.getValue() << endl;
    cout << "Copied value: " << a2.getValue() << endl << endl;

    a2.setValue(n2);

    cout << "After modifying copied object:" << endl;
    cout << "Original value: " << a1.getValue() << endl;
    cout << "Copied value: " << a2.getValue() << endl;

    return 0;
}
