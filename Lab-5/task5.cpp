#include <iostream>
using namespace std;

string charResult(char c) {
    if (isprint((unsigned char)c))
        return string(1, c);
    return "";
}

int main() {
    double value;
    cin >> value;
    
    int implicitInt = value;       // double -> int (implicit)
    float implicitFloat = value;   // double -> float (implicit)

    long long cStyleLL = (long long)value;        // C-style cast
    long long staticCastLL = static_cast<long long>(value); // static_cast

    char cStyleChar = (char)value;        // C-style cast
    char staticCastChar = static_cast<char>(value); // static_cast

    cout << "Original double value: " << value << endl;
    cout << "Result after implicit casting to int: " << implicitInt << endl;
    cout << "Result after implicit casting to float: " << implicitFloat << endl;
    cout << "Result after explicit casting to long long (C-style): " << cStyleLL << endl;
    cout << "Result after explicit casting to long long (static_cast): " << staticCastLL << endl;
    
    string c1 = charResult(cStyleChar);
    cout << "Result after explicit casting to char (C-style):" << (c1.empty() ? "" : " " + c1) << endl;

    string c2 = charResult(staticCastChar);
    cout << "Result after explicit casting to char (static_cast):" << (c2.empty() ? "" : " " + c2) << endl;



    return 0;
}
