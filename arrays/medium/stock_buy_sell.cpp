// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int>& arr) {
    int n = arr.size();
    int profit = 0;
    int buy = arr[0];

    for(int i=1; i<n; i++){
    
        profit = max(profit,arr[i] - buy);
        buy = min(arr[i],buy);
    
    }
    
    return profit;
}


int main(){
    return 0;
}

