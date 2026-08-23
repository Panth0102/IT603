#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> merge_array(vector<int> num1, vector<int> num2){
    int n1 = num1.size();
    int n2 = num2.size();
    int n3 = n1 + n2;
    vector<int> num3(n3);
    int i = 0,j = 0;
    while(i < n1 && j < n2){
        if(num1[i] < num2[j]){
            num3.push_back(num1[i]);
            i++;   
        }else{
            num3.push_back(num2[j]);
            j++;       
        }
    }
    while(i < n1){
        num3.push_back(num1[i]);
        i++;
    }

    while(j < n2){
        num3.push_back(num2[j]);
    }

    return num3;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n1, n2;
    cin >> n1;
    cin >> n2;
    
    vector<int> num1(n1);   
    vector<int> num2(n2);
    
    for(int i = 0; i < n1; i++){
        cin >> num1[i];
    }
    
    for(int i = 0; i < n2; i++){
        cin >> num2[i];
    }
    vector<int> num3(n1+n2);
    num3 = merge_array(num1,num2);
    for(int i = 0; i < (n1+n2); i++)
        cout << num3[i];
    
    return 0;
}

/*
4 
3
0 
2
7 
8 
-7 
-3 
-1
*/