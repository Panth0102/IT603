#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include <cctype>
using namespace std;

class LRUCache {
private:
    struct Node {
        int key, value;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    int capacity;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> map;

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insertFront(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void clear() {
        Node* curr = head->next;
        while (curr != tail) {
            Node* nxt = curr->next;
            delete curr;
            curr = nxt;
        }
        head->next = tail;
        tail->prev = head;
        map.clear();
    }

public:
    LRUCache(int cap) : capacity(cap) {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    LRUCache(const LRUCache& other) : capacity(other.capacity) {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        Node* curr = other.tail->prev;
        vector<pair<int,int>> order;
        while (curr != other.head) {
            order.push_back({curr->key, curr->value});
            curr = curr->prev;
        }
        for (int i = (int)order.size() - 1; i >= 0; i--) {
            Node* n = new Node(order[i].first, order[i].second);
            insertFront(n);
            map[order[i].first] = n;
        }
    }

    LRUCache& operator=(const LRUCache& other) {
        if (this != &other) {
            clear();
            capacity = other.capacity;
            Node* curr = other.tail->prev;
            vector<pair<int,int>> order;
            while (curr != other.head) {
                order.push_back({curr->key, curr->value});
                curr = curr->prev;
            }
            for (int i = (int)order.size() - 1; i >= 0; i--) {
                Node* n = new Node(order[i].first, order[i].second);
                insertFront(n);
                map[order[i].first] = n;
            }
        }
        return *this;
    }

    ~LRUCache() {
        clear();
        delete head;
        delete tail;
    }

    int get(int key) {
        auto it = map.find(key);
        if (it == map.end()) return -1;
        Node* node = it->second;
        removeNode(node);
        insertFront(node);
        return node->value;
    }

    void put(int key, int value) {
        auto it = map.find(key);
        if (it != map.end()) {
            Node* node = it->second;
            node->value = value;
            removeNode(node);
            insertFront(node);
            return;
        }
        if ((int)map.size() >= capacity) {
            Node* lru = tail->prev;
            removeNode(lru);
            map.erase(lru->key);
            delete lru;
        }
        Node* node = new Node(key, value);
        insertFront(node);
        map[key] = node;
    }

    friend ostream& operator<<(ostream& os, const LRUCache& cache) {
        os << "{";
        Node* curr = cache.head->next;
        bool first = true;
        while (curr != cache.tail) {
            if (!first) os << ", ";
            os << curr->key << "=" << curr->value;
            first = false;
            curr = curr->next;
        }
        os << "}";
        return os;
    }
};

int main() {
    stringstream buffer;
    buffer << cin.rdbuf();
    string text = buffer.str();

    vector<string> ops;
    {
        size_t i = 0;
        while (i < text.size()) {
            if (text[i] == '"') {
                size_t j = i + 1;
                string tok;
                while (j < text.size() && text[j] != '"') {
                    tok += text[j];
                    j++;
                }
                ops.push_back(tok);
                i = j + 1;
            } else {
                i++;
            }
        }
    }

    vector<vector<int>> args;
    {
        size_t i = 0;
        int depth = 0;
        vector<int> current;
        bool inNumberGroup = false;
        while (i < text.size()) {
            char c = text[i];
            if (c == '"') {
                size_t j = i + 1;
                while (j < text.size() && text[j] != '"') j++;
                i = j + 1;
                continue;
            }
            if (c == '[') {
                depth++;
                if (depth == 2) current.clear();
            } else if (c == ']') {
                if (depth == 2) args.push_back(current);
                depth--;
            } else if (isdigit((unsigned char)c) || (c == '-' && i + 1 < text.size() && isdigit((unsigned char)text[i+1]))) {
                if (depth >= 2) {
                    size_t j = i;
                    bool neg = false;
                    if (text[j] == '-') { neg = true; j++; }
                    int val = 0;
                    while (j < text.size() && isdigit((unsigned char)text[j])) {
                        val = val * 10 + (text[j] - '0');
                        j++;
                    }
                    current.push_back(neg ? -val : val);
                    i = j;
                    continue;
                }
            }
            i++;
        }
    }

    LRUCache* cache = nullptr;
    vector<string> results;

    for (size_t i = 0; i < ops.size(); i++) {
        const string& op = ops[i];
        if (op == "LRUCache") {
            int cap = args[i][0];
            cache = new LRUCache(cap);
            results.push_back("null");
        } else if (op == "put") {
            cache->put(args[i][0], args[i][1]);
            results.push_back("null");
        } else if (op == "get") {
            int val = cache->get(args[i][0]);
            results.push_back(to_string(val));
        }
    }

    cout << "[";
    for (size_t i = 0; i < results.size(); i++) {
        cout << results[i];
        if (i != results.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    delete cache;
    return 0;
}