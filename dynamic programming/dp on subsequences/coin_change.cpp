#include <iostream>
#include <queue>
#include<vector>
#include<unordered_map>
#include<string>
#include<unordered_set>
using namespace std;


int helper(int i , int amt , vector<int>arr , vector<int> &dp){
    if(amt == 0){
        return 0;
    }
    if(amt < 0){
        return INT_MAX;
    }

    if(dp[amt] != -1){
        return dp[amt];
    }

    priority_queue <int, vector<int>, greater<int>> mini;
    for(int j = 0; j<arr.size(); j++){    
        int ans  = 1 + helper(j , amt-arr[j] , arr , dp);
        mini.push(ans);
    }

    return dp[amt] = mini.top();
}

int tabular(vector<int>& arr, int amount) {
    int n = arr.size();
    vector<int> dp(amount + 1, INT_MAX);  // Initialize dp array with INT_MAX

    dp[0] = 0;  // Base case: To make amount 0, 0 coins are needed

    for (int amt = 1; amt <= amount; amt++) {
        for (int j = 0; j < arr.size(); j++) {
            if (amt >= arr[j] && dp[amt - arr[j]] != INT_MAX) {
                dp[amt] = min(dp[amt], 1 + dp[amt - arr[j]]);
            }
        }
    }

    return dp[amount] == INT_MAX ? -1 : dp[amount];
}


int perfectSum(vector<int>& arr , int amt) {

    int n = arr.size();


    vector<int> dp(amt+1 , -1);
    //return helper(0  , arr , sum , n , dp);
}