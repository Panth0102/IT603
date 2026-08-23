#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

    int n;
    cout << "Enter the size of vector: ";
    cin >> n;

    vector<int> prices(n);
    

    for(int i = 0; i< n; i++){
        cout << "Enter values at " << i << " : ";
        cin >> prices[i];
    }

    int minPrice = prices[0];

    int maxProfit = INT_MIN;

    for (int i = 0;i < n; i++){
        if (prices[i] < minPrice)
            minPrice = prices[i];

        int profit = prices[i] - minPrice;
            
        if(maxProfit < profit){
            maxProfit = profit;
        }
    }

    cout << maxProfit;
    
    return 0;
}
