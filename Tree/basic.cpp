#include<iostream>
#include<queue>

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

        vector<int> inorderTraversal(Node *root, vector<int>& ans){
            if(root == NULL) return ans;

            inorderTraversal(root->left, ans);
            ans.push_back(root->data);
            inorderTraversal(root->right, ans);
            return ans;
        }

        vector<int> postOrderTraversal(Node *root, vector<int>& ans){
            if(root == NULL) return ans;

            postOrderTraversal(root->left, ans);
            postOrderTraversal(root->right, ans);
            ans.push_back(root->data);
            return ans;
        }

        vector<int> preOrderTraversal(Node *root, vector<int>& ans){
            if(root == NULL) return ans;

            ans.push_back(root->data);
            preOrderTraversal(root->left, ans);
            preOrderTraversal(root->right, ans);
            return ans;
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

        vector<int> BFS(Node *root){
            vector<int> ans;
            if(root == NULL) return ans;

            queue<Node*> q;
            q.push(root);

            while(!q.empty()){
                Node* temp = q.front();
                ans.push_back(temp->data);
                q.pop();

                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            return ans;
        }

        void display(vector<int> ans){
            for(int i=0; i<ans.size(); i++){
                cout << ans[i] << " ";
            }
            cout << endl;
        }
};



int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> ans;
    cout << "DFS" << endl;
    cout << "Inorder: ";
    root->display(root->inorderTraversal(root, ans));
    ans.clear();
    
    cout << "Preorder: ";
    root->display(root->preOrderTraversal(root, ans));
    ans.clear();
    
    cout << "Postorder: ";
    root->display(root->postOrderTraversal(root, ans));
    ans.clear();

    cout << "Count of Nodes: " << root->countNodes(root) << endl;
    cout << "Height of Tree: " << root->height(root) << endl;

    cout << "Element 2: " << (root->search(root, 2)?"Found": "Not Found") << endl;

    cout << "BFS: ";
    root->display(root->BFS(root));

    cout << endl;
    return 0;
}