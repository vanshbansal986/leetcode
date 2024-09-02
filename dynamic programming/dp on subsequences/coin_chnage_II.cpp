#include <iostream>
#include <queue>
#include<vector>
#include<unordered_map>
#include<string>
#include<unordered_set>
using namespace std;


int helper(int i , int amt , vector<int>arr , vector<vector<int>> &dp){
    int n = arr.size();
    if(amt == 0){
        return 1;
    }

    if(i == n){
        return 0;
    }

    if(dp[i][amt] != -1){
        return dp[i][amt];
    }

    
    int inc = 0;
    if(amt - arr[i] >= 0){
        inc = helper(i , amt-arr[i] , arr , dp);
    }   
    int exc = helper(i+1 , amt , arr ,dp);

    

    return dp[i][amt] = inc + exc;
    
}

int tabular(vector<int>& arr , int amount){
    int n = arr.size();
    vector<vector<int>> dp(n+1 ,vector<int>(amount+1 , 0));

    for(int i=0; i<=n; i++){
        dp[i][0] = 1;
    }

    for(int i = n-1; i>=0; i--){
        for(int amt = 0; amt <=amount; amt++){
            int inc = 0;
            if(amt - arr[i] >= 0){
                inc = dp[i][amt-arr[i]];
            }   
            int exc = dp[i+1][amt];



            dp[i][amt] = inc + exc;
        }
    }

    return dp[0][amount];
}


int perfectSum(vector<int>& arr , int amt) {
    int n = arr.size();
    vector<vector<int>> dp(n+1 ,vector<int>(amt+1 , -1));

    return helper(0, amt , arr , dp);
}