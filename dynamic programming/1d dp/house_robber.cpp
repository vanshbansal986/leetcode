#include <iostream>
#include <queue>
#include<vector>
#include<unordered_map>
#include<string>
#include<unordered_set>
using namespace std;

int helper(int i , vector<int>& nums , vector<int> dp){
    if(i > nums.size()){
        return 0;
    }
    if(dp[i] != -1){
        return dp[i];
    }

    int take = INT_MIN;
    if(i+2 > nums.size()){
        take = nums[i] + helper(i+2 , nums , dp);
    }
    int not_take = helper(i+1 , nums , dp);

    return dp[i] = max(take , not_take);
}

int tabulation(vector<int>& nums){
    int n = nums.size();
    vector<int> dp(n+1 , -1);
    dp[0] = 0;
    dp[1] = nums[0];

    for(int i=2; i<=n; i++){
        int take = nums[i] + dp[i-2];
        int not_take = dp[i-1];

        dp[i] = min(take, not_take);
    }

    return dp[n];
}

int rob(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n+1 , -1);
    return helper(0,nums,dp);
}