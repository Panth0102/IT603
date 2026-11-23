#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

Node* buildTree(vector<int>& arr) {
    if (arr.empty() || arr[0] == -1)
        return nullptr;
    Node* root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < arr.size()) {
        Node* curr = q.front();
        q.pop();
        if (arr[i] != -1) {
            curr->left = new Node(arr[i]);
            q.push(curr->left);
        }
        i++;

        if (i < arr.size()) {
            if (arr[i] != -1) {
                curr->right = new Node(arr[i]);
                q.push(curr->right);
            }
            i++;
        }
    }

    return root;
}

void display(Node* root) {
    if (root == nullptr)
        return;

    display(root->left);
    cout << root->data << " ";    
    display(root->right);
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    Node* root = buildTree(arr);
    display(root);

    return 0;
}