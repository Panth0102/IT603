#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    
    int* arr = new int[n];
    for(int i = 0; i < n; i++){
        cin >>arr[i];
    }

    int min = INT_MAX;
    int max = INT_MIN;
    long long int sum = 0, cnt = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
        if(min > arr[i])
            min = arr[i];
        if(max < arr[i])
            max = arr[i];
        if(arr[i] % 2 == 0)
            cnt++;
    }
    
    int exc = 0;
    for(int i = 0; i < n/2; i++){
        exc = arr[i];
        arr[i] = arr[n-i-1];
        arr[n-i-1] = exc;
    }
    
    if(n == 0){
        min = max = 0;
    }
    cout << "Sum: " << sum << " " << endl;
    cout << "Minimum: " << min << " " << endl;
    cout << "Maximum: " << max << " " <<endl;
    cout << "Even Count: "<< cnt << " " << endl;
    cout << "Reversed Array:";
    for(int i = 0; i < n; i++){
        cout << " " << arr[i] ;
    }
    
    delete[] arr;
    return 0;
}
