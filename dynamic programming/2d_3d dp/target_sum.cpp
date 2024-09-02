#include <iostream>
#include <queue>
#include<vector>
#include<unordered_map>
#include<string>
#include<unordered_set>
using namespace std;

int helper(int i , int target , vector<int>& nums, int n , vector<vector<int>> dp , int sum){
    if(i == n){
        if(target == 0){
            return 1;
        }

        return 0;
    }

    // Calculate the adjusted index for dp array
    int dp_index = target + sum;
    // Ensure dp_index is within valid bounds
    if (dp_index < 0 || dp_index > 2 * sum) {
        return 0;
    }
    // Use the stored value if it's already calculated
    if (dp[i][dp_index] != -1) {
        return dp[i][dp_index];
    }
    int plus = 0 , minus = 0;
    plus = helper(i+1 ,target-nums[i] , nums , n , dp , sum);
    minus = helper(i+1 ,target+nums[i] , nums , n , dp , sum);


    return dp[i][target + sum] = plus + minus;
}

int tabular(vector<int>& nums, int target){
    int n = nums.size();
    vector<vector<int>> dp(n+1 , vector<int>(target+1 , 0));
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += nums[i];
    } 

    dp[n][0] = 1;

    for(int i = n-1; i>=0; i++){
        for(int k = 0; k <= target + sum; k++){
            int plus = 0 , minus = 0;
            plus = dp[i+1][k-nums[i]];
            minus = dp[i+1][k+nums[i]];


            dp[i][k + sum] = plus + minus;
        }
    }

    return dp[0][target+sum];
}



int solve(vector<int>& nums, int target) {
    int n = nums.size();
    vector<vector<int>> dp(n+1 , vector<int>(target+1 , -1));
}