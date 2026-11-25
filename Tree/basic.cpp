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

        void insert(Node*& root, int val) {
            Node* newNode = new Node(val);
            if (root == nullptr) {
                root = newNode;
                return;
            }
            queue<Node*> q;
            q.push(root);
            while (!q.empty()) {
                Node* temp = q.front();
                q.pop();
        
                if (temp->left == nullptr) {
                    temp->left = newNode;
                    return;
                }
                else {
                    q.push(temp->left);
                }
        
                if (temp->right == nullptr) {
                    temp->right = newNode;
                    return;
                }
                else {
                    q.push(temp->right);
                }
            }
        }

        Node* buildTree(vector<string>& arr) {
            if(arr.empty() || arr[0] == "null")
                return nullptr;
        
            Node* root = new Node(stoi(arr[0]));
            queue<Node*> q;
            q.push(root);
        
            int i = 1;
        
            while(!q.empty() && i < arr.size()) {
        
                Node* curr = q.front();
                q.pop();
        
                // Left child
                if(i < arr.size() && arr[i] != "null") {
                    curr->left = new Node(stoi(arr[i]));
                    q.push(curr->left);
                }
                i++;
        
                // Right child
                if(i < arr.size() && arr[i] != "null") {
                    curr->right = new Node(stoi(arr[i]));
                    q.push(curr->right);
                }
                i++;
            }
        
            return root;
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
    Node* root = NULL;
    Node obj(0);

    obj.insert(root, 1);
    obj.insert(root, 2);
    obj.insert(root, 3);
    obj.insert(root, 4);
    obj.insert(root, 5);
    obj.insert(root, 6);
    obj.insert(root, 7);

    vector<int> ans;
    cout << "DFS" << endl;
    cout << "Inorder: ";
    obj.display(obj.inorderTraversal(root, ans));
    ans.clear();
    
    cout << "Preorder: ";
    obj.display(obj.preOrderTraversal(root, ans));
    ans.clear();
    
    cout << "Postorder: ";
    obj.display(obj.postOrderTraversal(root, ans));
    ans.clear();

    cout << "Count of Nodes: " << obj.countNodes(root) << endl;
    cout << "Height of Tree: " << obj.height(root) << endl;

    cout << "Element 2: " << (obj.search(root, 2)?"Found": "Not Found") << endl;

    cout << "BFS: ";
    obj.display(obj.BFS(root));

    cout << endl;
    return 0;
}