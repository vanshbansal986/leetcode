#include <iostream>
#include <queue>
#include<vector>
#include<unordered_map>
#include<string>
#include<unordered_set>
using namespace std;


int helper(int i , int k , vector<int>arr , vector<vector<int>> &dp){
    if(k == 0){
        return 1;
    }
    int n = arr.size();
    
    if(i >= n){
        return 0;
    }
    
    if(dp[i][k] != -1){
        return dp[i][k];
    }
    
    
    int inc = 0;
    if(k - arr[i] >= 0){
        inc = helper(i+1 , k-arr[i] , arr , dp);
    }

    int exc = helper(i+1 , k , arr , dp);

    return dp[i][k] = inc + exc;
}

bool tabular(vector<int>arr, int sum){
    int n = arr.size();
    
    vector<vector<int>> dp(n+1 , vector<int>(sum+1 , -1));

    for(int i=0; i<=n; i++){
        dp[i][0] = 1;
    }

    for(int i = n-1; i>=0; i--){
        for(int k = 0; k<=sum; k++){

            int inc = 0;
            if(k - arr[i] >= 0){
                inc = dp[i+1][k-arr[i]];
            }

            int exc = dp[i+1][k];

            dp[i][k] = inc + exc;
        }
    }

    return dp[0][sum];
}

int perfectSum(vector<int>& arr , int k) {

    int n = arr.size();


    vector<vector<int>> dp(n+1 , vector<int>(k+1 , -1));
    //return helper(0  , arr , sum , n , dp);
}