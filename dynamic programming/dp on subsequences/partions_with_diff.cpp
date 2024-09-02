#include <iostream>
#include <queue>
#include<vector>
#include<unordered_map>
#include<string>
#include<unordered_set>
using namespace std;


int helper(int i , int amt , vector<int>arr , vector<vector<int>> &dp){
    int n = arr.size();
    // if(amt == 0){
    //     return 1;
    // }
    
    if(i == n-1){
        if(amt == 0 && arr[n-1] == 0){
            return 2;
        }

        if(amt == 0 || amt == arr[n-1]){
            return 1;
        }

        return 0;
    }

    if(dp[i][amt] != -1){
        return dp[i][amt];
    }

    
    int inc = 0;
    if(amt - arr[i] >= 0){
        inc = helper(i+1 , amt-arr[i] , arr , dp);
    }

    int exc = helper(i+1 , amt , arr , dp);

    return dp[i][amt] = inc + exc;

}

int tabular(vector<int>& arr, int d) {
    int n = arr.size();
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];
    }

    if((sum-d)/2 < 0 || (sum-d)%2 != 0){
        return false;
    }

    int target = (sum-d)/2;

    vector<vector<int>> dp(n+1 , vector<int> (sum+1 , 0));

    if(arr[n-1] == 0){
        dp[n-1][0] = 2;
    }
    dp[n-1][0] = 1;
    if(arr[n-1] != 0 && arr[n-1] <= target){
        dp[n-1][arr[n-1]] = 1;
    }

    for(int i = n-2; i>=0; i--){
        for(int amt = 0; amt <= target; amt++){

            int inc = 0;
            if(amt - arr[i] >= 0){
                inc = dp[i+1][amt-arr[i]];
            }

            int exc = dp[i+1][amt];

            dp[i][amt] = inc + exc;
        }
    }

    return dp[0][target];

}


int countPartitions(int n, int d, vector<int>& arr) {
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];
    }

    if((sum-d)/2 < 0 || (sum-d)%2 != 0){
        return false;
    }

    int target = (sum-d)/2;

    vector<vector<int>> dp(n+1 , vector<int> (sum+1 , -1));
    return helper(0,target, arr , dp);
}