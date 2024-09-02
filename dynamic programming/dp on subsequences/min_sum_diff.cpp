#include <iostream>
#include <queue>
#include<vector>
#include<unordered_map>
#include<string>
#include<unordered_set>
using namespace std;


int helper(int i , int size , int total , int n  , vector<int>arr , vector<vector<int>> &dp){
    if(size > n/2){
        return 0;
    }
    if(i >= n){
        return INT_MAX;
    }

    if(dp[i][size] != -1){
        return dp[i][size];
    }

    int inc = INT_MAX;
    int exc = INT_MAX;
    if(size + 1 <= n/2){
        inc = arr[i] + helper(i+1 , size + 1 , total , n , arr, dp);
        exc = helper(i+1 , size , total , n , arr , dp);
    }

    int mini;
    if(size == n/2){
        mini = total - 2*inc;
    }
        
}

bool tabular(vector<int>arr, int sum){
    int n = arr.size();
    int sum = 0;

    
}

int minimumDifference(vector<int>& arr) {

    int n = arr.size();
    int total = 0;
    for(int i =0; i<n; i++){
        total += arr[i];
    }

    vector<vector<int>> dp(n+1 , vector<int>(total+1 , -1));
    //return helper(0  , arr , sum , n , dp);
}