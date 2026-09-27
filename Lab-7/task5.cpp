#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <cctype>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int v) : val(v), next(nullptr) {}
    ListNode(int v, ListNode* n) : val(v), next(n) {}

    bool operator<(const ListNode& other) const {
        return this->val > other.val;
    }
};

struct NodePtrCompare {
    bool operator()(ListNode* a, ListNode* b) const {
        return *a < *b;
    }
};

class LinkedList {
public:
    ListNode* head;

    LinkedList() : head(nullptr) {}

    LinkedList(const LinkedList& other) : head(nullptr) {
        copyFrom(other);
    }

    LinkedList& operator=(const LinkedList& other) {
        if (this != &other) {
            clear();
            copyFrom(other);
        }
        return *this;
    }

    ~LinkedList() {
        clear();
    }

    void pushBack(int val) {
        ListNode* node = new ListNode(val);
        if (!head) {
            head = node;
            return;
        }
        ListNode* curr = head;
        while (curr->next) curr = curr->next;
        curr->next = node;
    }

    friend ostream& operator<<(ostream& os, const LinkedList& list) {
        os << "[";
        ListNode* curr = list.head;
        bool first = true;
        while (curr) {
            if (!first) os << ",";
            os << curr->val;
            first = false;
            curr = curr->next;
        }
        os << "]";
        return os;
    }

private:
    void clear() {
        ListNode* curr = head;
        while (curr) {
            ListNode* nxt = curr->next;
            delete curr;
            curr = nxt;
        }
        head = nullptr;
    }

    void copyFrom(const LinkedList& other) {
        if (!other.head) {
            head = nullptr;
            return;
        }
        head = new ListNode(other.head->val);
        ListNode* dst = head;
        ListNode* src = other.head->next;
        while (src) {
            dst->next = new ListNode(src->val);
            dst = dst->next;
            src = src->next;
        }
    }
};

LinkedList mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, NodePtrCompare> pq;

    for (ListNode* node : lists) {
        if (node) pq.push(node);
    }

    LinkedList result;
    ListNode* tail = nullptr;

    while (!pq.empty()) {
        ListNode* smallest = pq.top();
        pq.pop();

        ListNode* newNode = new ListNode(smallest->val);
        if (!result.head) {
            result.head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        if (smallest->next) pq.push(smallest->next);
    }

    return result;
}

int main() {
    stringstream buffer;
    buffer << cin.rdbuf();
    string text = buffer.str();

    vector<vector<int>> rawLists;
    int i = 0, len = (int)text.size();
    int depth = 0;
    vector<int> current;

    while (i < len) {
        char c = text[i];
        if (c == '[') {
            depth++;
            if (depth == 2) current.clear();
        } else if (c == ']') {
            if (depth == 2) rawLists.push_back(current);
            depth--;
        } else if (isdigit((unsigned char)c) || (c == '-' && i + 1 < len && isdigit((unsigned char)text[i+1]))) {
            int j = i;
            bool neg = false;
            if (text[j] == '-') { neg = true; j++; }
            int val = 0;
            while (j < len && isdigit((unsigned char)text[j])) {
                val = val * 10 + (text[j] - '0');
                j++;
            }
            if (depth >= 2) current.push_back(neg ? -val : val);
            i = j;
            continue;
        }
        i++;
    }

    vector<ListNode*> lists;
    vector<LinkedList*> owners;

    for (auto& vals : rawLists) {
        LinkedList* ll = new LinkedList();
        for (int v : vals) ll->pushBack(v);
        owners.push_back(ll);
        lists.push_back(ll->head);
    }

    LinkedList merged = mergeKLists(lists);

    cout << merged << endl;

    for (auto ll : owners) delete ll;

    return 0;
}