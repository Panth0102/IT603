#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Student{
    string name;
    int rollNo;
public:
    Student(string name, int rollNo){
        this->name = name;
        this->rollNo = rollNo;
        cout << "Constructor called for Student " << rollNo << endl;
    }
    Student(const Student &s){
        name = s.name;
        rollNo = s.rollNo;
        cout << "Copy Constructor called for Student " << rollNo << endl;
    }
    ~Student(){
        cout << "Destructor called for Student " << rollNo << endl;
    }
};

int main() {
    string name;
    int rollNo;
    getline(cin, name);
    cin >> rollNo;
    Student s1(name, rollNo);
    Student s2(s1);
    return 0;
}
