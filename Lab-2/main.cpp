#include <iostream>
#include "Calculator.h"

using namespace std;

int main() {
    Calculator calc;

    cout << "Addition: " << calc.add(10, 5) << endl;
    cout << "Subtraction: " << calc.subtract(10, 5) << endl;

    return 0;
}