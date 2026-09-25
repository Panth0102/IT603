#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

class BankAccount{
    long long accNo;
    double balance;
    string accName;
    int status;
public:
    BankAccount(){
        accNo = 0;
        balance = 0.0;
        accName = "Unknown";
        status = 1;
    }
    BankAccount(string name){
        this->accName = name;
        accNo = 0;
        balance = 0.0;        
        status = 2;
    }
    BankAccount(string name, long long accNo){
        this->accName = name;
        this->accNo = accNo;
        balance = 0.0;        
        status = 3;
    }
    BankAccount(string name, long long accNo, double balance){
        this->accName = name;
        this->accNo = accNo;
        this->balance = balance;
        status = 4;
    }
    void display(){
        cout << "Account Holder: " << accName << endl;
        cout << "Account Number: " << accNo << endl;
        cout << "Balance: " << fixed << setprecision(2) << balance << endl;
        cout << "Constructor Type: ";
        switch(status){
            case 1: cout << "Default Constructor" << endl; break;
            case 2: cout << "Name Constructor" << endl; break;
            case 3: cout << "Name + Account Number Constructor" << endl; break;
            case 4: cout << "Name + Account Number + Balance Constructor" << endl; break;
        }
        cout << endl;
    }
};  

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int type;
        cin >> type;
        if (type == 0) {
            BankAccount account;
            account.display();
        }
        else if (type == 1) {
            string name;
            cin >> name;

            BankAccount account(name);
            account.display();
        }
        else if (type == 2) {
            string name;
            long long accNo;
            cin >> name >> accNo;

            BankAccount account(name, accNo);
            account.display();
        }
        else if (type == 3) {
            string name;
            long long accNo;
            double balance;

            cin >> name >> accNo >> balance;

            BankAccount account(name, accNo, balance);
            account.display();
        }
        
    }
    return 0;
}
