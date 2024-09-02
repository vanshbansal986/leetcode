#include <iostream>
#include <queue>
#include<vector>
#include<unordered_map>
#include<string>
#include<unordered_set>
using namespace std;

bool helper(int i , vector<int>arr, int sum , int n , vector<vector<int>> dp){
    if(sum == 0){
        return true;
    }
    
    if(i >= n || sum < 0){
        return false;
    }

    if(dp[i][sum] != -1){
        return dp[i][sum];
    }

    bool inc = helper(i+1 , arr , sum - arr[i] , n , dp);
    bool exc = helper(i+1 , arr , sum - 0 , n , dp);

    return dp[i][sum] = inc || exc;

}

bool tabular(vector<int>arr, int sum){
    int n = arr.size();
    vector<vector<bool>> dp(n+1 , vector<bool> (sum+1 , 0));

    for(int i =0; i<n; i++){
        dp[i][0] = true;
    }
    dp[0][arr[0]] = true;

    for(int i = 1; i<n; i++){
        for(int target = 1; target<= sum; target++){
            
            bool inc = false;
            if(target >= arr[i]){
                inc = dp[i-1][target - arr[i]];
            }

            bool exc = dp[i-1][target];
            
            dp[i][target] = inc || exc;
        }
        
    }
    
    return dp[n][sum];
}

bool isSubsetSum(vector<int>arr, int sum){
    int n = arr.size();
    vector<vector<int>> dp(n+1 , vector<int> (sum+1 , -1));
    return helper(0  , arr , sum , n , dp);
}