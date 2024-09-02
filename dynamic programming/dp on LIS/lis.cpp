#include <iostream>
#include <queue>
#include<vector>
#include<unordered_map>
#include<string>
#include<unordered_set>
using namespace std;

int helper(int i , int prev_ind , vector<int> nums , vector<vector<int>> &dp){
    if(i == nums.size()){
        return 0;
    }

    if(dp[i][prev_ind + 1] != -1){
        return dp[i][prev_ind + 1];
    }

    int inc = 0;
    if(prev_ind == -1 || nums[i] > nums[prev_ind]){
        int new_prev_ind = i;
        inc = 1 + helper(i+1 , new_prev_ind , nums , dp);
    }

    int exc = helper(i+1 , prev_ind , nums , dp);

    return dp[i][prev_ind + 1] = max(inc , exc);
}





int tabular(vector<int> nums){
    int n = nums.size();

    vector<vector<int>> dp(n+1 , vector<int> (n+2 , 0));

    for(int i = n-1; i>=0; i--){
        for(int prev_ind = n-1; prev_ind >= -1; prev_ind--){
            int inc = 0;
            if(prev_ind == -1 || nums[i] > nums[prev_ind]){
                int new_prev_ind = i;
                inc = 1 + dp[i+1][new_prev_ind + 1];
            }

            int exc = dp[i+1][prev_ind+1];

            dp[i][prev_ind + 1] = max(inc , exc);
        }
    }

    return dp[0][0];
}



int lengthOfLIS(vector<int>& nums){
    int n = nums.size();

    vector<vector<int>> dp(n+1 , vector<int> (n+2 , -1));

    return helper(0,-1, nums , dp);

}