#include <iostream>
#include <queue>
#include<vector>
#include<unordered_map>
#include<string>
#include<unordered_set>
using namespace std;



bool helper(int i , int sum1 , int n  , vector<int>arr , vector<vector<int>> &dp){
    if(sum1 == 0){
        return true;
    }

    if(sum1 < 0 || i>=n){
        return false;
    }

    if(dp[i][sum1] != -1){
        return dp[i][sum1];
    }

    int inc = helper(i+1 , sum1 - arr[i] , n , arr , dp);
    int exc = helper(i+1 , sum1 , n , arr , dp);

    return dp[i][sum1] = inc || exc;
}

bool tabular(vector<int>arr, int sum){
    int n = arr.size();
    int sum = 0;

    for(int i =0; i<n; i++){
        sum += arr[i];
    }
    if(sum % 2 != 0){
        return false;
    }

    vector<vector<bool>> dp(n+1 , vector<bool>(sum+1 , 0));
    for(int i=0; i<n; i++){
        dp[i][0] = true;
    }

    for(int i=n-1; i>=0; i--){
        for(int k = 0; k<=sum/2; k++){
            int inc = false;
            
            if(k >= arr[i]){
                inc = dp[i+1] [k - arr[i]];
            }

            int exc = dp[i+1][k];

            dp[i][k] = inc || exc;
        }
    }
    
    return dp[0][sum/2];
    
}

bool isSubsetSum(vector<int>arr){
    int n = arr.size();
    int sum = 0;
    for(int i =0; i<n; i++){
        sum += arr[i];
    }

    if(sum %2 != 0){
        return false;
    }
    vector<vector<int>> dp(n+1 , vector<int>(sum+1 , -1));
    //return helper(0  , arr , sum , n , dp);
}