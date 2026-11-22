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