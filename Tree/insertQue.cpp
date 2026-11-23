#include<iostream>
using namespace std;

class TreeNode {
    public:
        int val;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int value) {
            val = value;
            left = nullptr;
            right = nullptr;
        }
};

class Solution {
    public:
        TreeNode* insertIntoBST(TreeNode* root, int val) {
            if(root == nullptr) return new TreeNode(val);
            if(val < root->val) root->left = insertIntoBST(root->left, val);
            else if(val > root->val) root->right = insertIntoBST(root->right, val);
            return root;
        }

        TreeNode*  buildTree(vector<int>& arr) {
            if (arr.empty() || arr[0] == -1) return nullptr;
            TreeNode* root = new TreeNode(arr[0]);
            for (int i = 1; i < arr.size(); i++) {
                if (arr[i] != -1) {
                    insertIntoBST(root, arr[i]);
                }
            }
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
                    result.push_back(to_string(curr->val));
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
};

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution sol;
    TreeNode* root = sol.buildTree(arr);

    sol.display(root);
    cout << endl;

    int val;
    cin >> val;
    sol.insertIntoBST(root, val);

    sol.display(root);

    return 0;
}