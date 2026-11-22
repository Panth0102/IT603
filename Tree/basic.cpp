#include<iostream>

using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val){
            data = val;
            left = NULL;
            right = NULL;
        }

        void inorderTraversal(Node *root){
            if(root == NULL) return;

            inorderTraversal(root->left);
            cout << root->data << " ";
            inorderTraversal(root->right);
        }

        void postOrderTraversal(Node *root){
            if(root == NULL) return;

            postOrderTraversal(root->left);
            postOrderTraversal(root->right);
            cout << root->data << " ";
        }

        void preOrderTraversal(Node *root){
            if(root == NULL) return;

            cout << root->data << " ";
            preOrderTraversal(root->left);
            preOrderTraversal(root->right);
        }

        int countNodes(Node *root){
            if(root == NULL) return 0;
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
        
        int height(Node *root){
            if(root == NULL) return 0;
            return 1 + max(height(root->left), height(root->right));
        }

        bool search(Node *root, int key){
            if(root == NULL) return false;
            if(root->data == key)   return true;
            return search(root->left, key) || search(root->right, key);
        }
};



int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->inorderTraversal(root);
    cout << endl;
    root->preOrderTraversal(root);
    cout << endl;
    root->postOrderTraversal(root);
    cout << endl;
    cout << root->countNodes(root) << endl;
    cout << root->height(root) << endl;

    cout << (root->search(root, 2)?"Found": "Not Found") << endl;
    return 0;
}