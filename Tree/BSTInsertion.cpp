#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
class TreeNode{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value){
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

TreeNode *createnode(TreeNode *root, int val){
    if (root == NULL) return new TreeNode(val);
    if (val < root->data) root->left = createnode(root->left, val);
    if (val > root->data) root->right = createnode(root->right, val);
    return root;
}

void display(TreeNode* root) {
    if (root == nullptr)
        return;

    queue<TreeNode*> q;
    q.push(root);

    vector<string> result;

    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();

        if (curr == nullptr) {
            result.push_back("null");
        }
        else {
            result.push_back(to_string(curr->data));
            q.push(curr->left);
            q.push(curr->right);
        }
    }
    while (!result.empty() && result.back() == "null") {
        result.pop_back();
    }
    for (string x : result) {
        cout << x << " ";
    }

    cout << endl;
}

TreeNode* deleteNode(TreeNode* root, int key) {
    if(root==nullptr) return nullptr;

    if(key < root->data)    root->left = deleteNode(root->left, key);
    else if(key > root->data)    root->right = deleteNode(root->right, key);
    else{
        if(root->left == nullptr && root->right == nullptr){
            delete root;
            return nullptr;
        }else if(root->left == nullptr){
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }else if(root->right == nullptr){
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }else{
            TreeNode* temp = root->right;
            while(temp->left != nullptr){
                temp = temp->left;
            }
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}


int main(){
    int n;
    cin >> n;
    TreeNode* root = NULL;
    
    for(int i = 0; i < n; i++){
        string x;
        cin >> x;
    
        if(x == "null") continue;
        else{
            int val = stoi(x);
            root = createnode(root, val);
        }
    }

    cout << "Level-order Traversal of the BST: ";
    display(root);

    int val;
    cin >> val;

    root = createnode(root, val);
    cout << "Level-order Traversal of the BST: ";
    display(root);
    return 0;
}