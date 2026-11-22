#include <iostream>
#include <stdexcept>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    double balance;

public:
    BankAccount(int acc, double bal) {
        accountNumber = acc;
        balance = bal;
    }

    void deposit(double amount) {
        if (amount <= 0)
            throw invalid_argument("Invalid deposit amount");

        balance += amount;
    }

    void withdraw(double amount) {
        if (amount <= 0)
            throw invalid_argument("Invalid withdrawal amount");

        if (amount > balance)
            throw runtime_error("Insufficient balance");

        balance -= amount;
    }

    void display() {
        cout << "Account: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main() {
    BankAccount account(101, 500);

    try {
        account.deposit(2000);
        account.withdraw(3000);
        account.display();
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}