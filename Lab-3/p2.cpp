#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int cnt(int n){
    static int count = 0;
    if(n == 0) return count;
    int temp = n;
    while(temp > 0){
        if(temp%10 == 1){
            count++;
        }
        temp /= 10;
    }
    return cnt(n-1);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    cout << cnt(n);
    return 0;
}
