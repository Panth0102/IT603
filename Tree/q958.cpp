#include<iostream>
#include<queue>

using namespace std;

class TreeNode{
    public: 
        int data;
        TreeNode *left;
        TreeNode *right;
    
        TreeNode(int val){
            data = val;
            left = NULL;
            right = NULL;
        }
};

class Solution{
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool flag = false;
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp == NULL) flag=true;
            else{
                if(flag) return false;
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        return true;
    }
};

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    Solution sol;
    if(sol.isCompleteTree(root)){
        cout << "The tree is a complete binary tree." << endl;
    } else {
        cout << "The tree is not a complete binary tree." << endl;
    }
    return 0;
}