#include <iostream>
#include <string>
using namespace std;

class Number {
    struct Node {
        int digit;
        Node* next;
        Node(int d) {
            digit = d;
            next = nullptr;
        }
    };
    Node* head;

public:
    Number() {
        head = nullptr;
    }

    void insert(int digit) {
        Node* newNode = new Node(digit);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void input(string s) {
        bool inside = false;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '[') {
                inside = true;
                continue;
            }
            if (s[i] == ']') {
                inside = false;
                continue;
            }
            if (inside && s[i] >= '0' && s[i] <= '9') {
                insert(s[i] - '0');
            }
        }
    }

    Number& operator=(const Number& other) {
        if (this == &other)
            return *this;
        head = nullptr;
        Node* temp = other.head;
        while (temp != nullptr) {
            insert(temp->digit);
            temp = temp->next;
        }
        return *this;
    }

    Number operator+(const Number& other) const {
        Number result;
        Node* p = head;
        Node* q = other.head;
        int carry = 0;
        while (p != nullptr || q != nullptr || carry != 0) {
            int sum = carry;
            if (p != nullptr) {
                sum += p->digit;
                p = p->next;
            }
            if (q != nullptr) {
                sum += q->digit;
                q = q->next;
            }
            result.insert(sum % 10);
            carry = sum / 10;
        }
        return result;
    }

    friend ostream& operator<<(ostream& out, const Number& num) {
        out << "[";
        Node* temp = num.head;
        while (temp != nullptr) {
            out << temp->digit;
            if (temp->next != nullptr)
                out << ",";
            temp = temp->next;
        }
        out << "]";
        return out;
    }
};

int main() {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    Number n1, n2;
    n1.input(s1);
    n2.input(s2);
    Number n3 = n1 + n2;
    cout << n3;
    return 0;
}
