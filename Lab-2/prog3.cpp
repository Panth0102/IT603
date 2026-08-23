#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void triplets(vector<int> num){
    int n = num.size();    
    vector<vector <int>> num2;
    vector<int> num3;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            for(int k = j+1; k < n; k++){
                if(num[i] + num[j] + num[k] == 0){
                    num3.push_back(num[i]);
                    num3.push_back(num[j]);
                    num3.push_back(num[k]);
                    num2.push_back(num3);
                    num3.pop_back();
                    num3.pop_back();
                    num3.pop_back();
                }
            }
        }
    }
    
    cout << num2.size() << endl;
    
    for(auto i: num2){
        sort(i.begin(),i.end());
    }
    sort(num2.begin(),num2.end());
    
    for(auto i: num2){
        for(auto j : i){
            cout << j << " ";    
        }
        cout << endl;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n1;
    cin >> n1;
    vector<int> num1(n1);
    for(int i = 0; i < n1; i++){
        cin >> num1[i];        
    }
    triplets(num1);
    return 0;
}
