#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
// Inorder and Postorder


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
    
        void inorderTraversal(TreeNode *root){
            if (root == NULL)
                return;
    
            inorderTraversal(root->left);
            cout << root->data << " ";
            inorderTraversal(root->right);
        }
    
        void postOrderTraversal(TreeNode *root){
            if (root == NULL)
                return;
    
            postOrderTraversal(root->left);
            postOrderTraversal(root->right);
            cout << root->data << " ";
        }
    
        void preOrderTraversal(TreeNode *root){
            if (root == NULL)
                return;
    
            cout << root->data << " ";
            preOrderTraversal(root->left);
            preOrderTraversal(root->right);
        }
    
        int countNodes(TreeNode *root){
            if (root == NULL)
                return 0;
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
    
        int height(TreeNode *root){
            if (root == NULL)
                return 0;
            return 1 + max(height(root->left), height(root->right));
        }
    
        bool search(TreeNode *root, int key){
            if (root == NULL)
                return false;
            if (root->data == key)
                return true;
            return search(root->left, key) || search(root->right, key);
        }
    };

class Solution{
public:
    unordered_map<int, int> map;
    int index;
    TreeNode *buildTreeInPo(vector<int> &inorder, vector<int> &postorder){
        for (int i = 0; i < inorder.size(); i++)
        {
            map[inorder[i]] = i;
        }
        index = postorder.size() - 1;
        return help(postorder, 0, inorder.size() - 1);
    }

    TreeNode *help(vector<int> &postorder, int start, int end){
        if (start > end)
            return nullptr;

        // Value changes as the index of postoorder moves, and is inserted
        int val = postorder[index--];
        TreeNode *root = new TreeNode(val);

        int mid = map[val];

        root->right = help(postorder, mid + 1, end);
        root->left = help(postorder, start, mid - 1);
        return root;
    }

    // Inorder and Preorder
    TreeNode *buildTreePrIn(vector<int> &preorder, vector<int> &inorder){
        for (int i = 0; i < inorder.size(); i++)
        {
            map[inorder[i]] = i;
        }
        return helper(preorder, 0, inorder.size() - 1);
    }

    TreeNode *helper(vector<int> preorder, int start, int end){
        if (start > end)
            return nullptr;

        // Value changes as the index of preoorder moves, and is inserted
        int val = preorder[index++];
        TreeNode *root = new TreeNode(val);

        // The start value of preorder would be root, so all the value on it's left are left child and ones in right are right child
        int mid = map[val];

        root->left = helper(preorder, start, mid - 1);
        root->right = helper(preorder, mid + 1, end);
        return root;
    }
};