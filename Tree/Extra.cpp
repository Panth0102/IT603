// BASIC BINARY TREE REPRESENTATION
// #include <bits/stdc++.h>

#include<iostream>
#include<algorithm>

using namespace std;
struct Node{
    public:
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val){
        data=val;
        left=right=NULL;
    }
};
int main(){
    struct Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->right=new Node(5);
}




// BINARY SEARCH
// #include <bits/stdc++.h>
using namespace std;
struct Item{
    int key;
    string value;
};
int binarySearch(Item A[],int n, int key){
    int low=0;
    int high=n-1;
    while(low <= high){
        int mid=low+(high-low)/2;
        if(A[mid].key==key){
            return mid;
        }
        else if(key< A[mid].key){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return -1;
};
int main(){
    Item A[5]={{10,"ABC"},{20,"PQR"},{30,"XYZ"}};
    int key;
    cout<<"Enter key: ";
    cin>>key;
    int pos=binarySearch(A,5,key);
    if(pos==-1){
        cout<<"Key not found..";
    }
    else{
        cout<<"Value: "<<A[pos].value;
    }
    return 0;
}