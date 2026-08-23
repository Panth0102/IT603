#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    vector<int> num(n);
    for(int i = 0; i< n; i++){
        cin >> num[i];
    }
    
    int count = 0;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            if(num[i] > num[j]){
                count++;
            }
        }
    }
    
    cout << count;
    return 0;
}