#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int cnt_sequence(vector<int> num){
    if(num.empty()) return 0;
    
    sort(num.begin(), num.end());
    int cnt = 1, max_val = 1;
    for(int i = 0; i+1 < num.size(); i++){
        if (num[i] == num[i + 1]) {
            continue;
        }
        if(num[i+1] == num[i] + 1){
            cnt++;
        }else{
            cnt = 1;
        }
        max_val = max_val > cnt ? max_val : cnt;
    }
    return max_val;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    vector<int> num(n);
    for(int i = 0; i < n; i++){
        cin >> num[i];
    }
    int cnt = cnt_sequence(num);
    cout << cnt;
    
    return 0;
}
