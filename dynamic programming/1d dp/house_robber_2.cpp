#include <iostream>
#include <queue>
#include<vector>
#include<unordered_map>
#include<string>
#include<unordered_set>
using namespace std;

int helper(int i , vector<int>& nums , vector<int> dp , bool f){
    if(i >= nums.size()){
        return 0;
    }
    if(dp[i] != -1){
        return dp[i];
    }


    int take;
    if(i == 0){
        take = nums[i] + helper(i+2 , nums , dp , true);
    }
    else if( i== nums.size()-1 && f == true){
        return 0;
    }
    else{
        take = nums[i] + helper(i+2 , nums , dp , f);
    }

    int not_take = helper(i+1 , nums , dp , f);
    
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

        dp[i] = max(take, not_take);
    }

    return dp[n];
}

int rob(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n+1 , -1);

    vector<int> nums1(n-1);
    for(int i=0; i<n-1; i++){
        nums1[i] = nums[i];
    }
    vector<int> nums2(n-1);
    for(int i=1; i<n; i++){
        nums2[i] = nums[i];
    }

    return max(tabulation(nums1) , tabulation(nums2));
}