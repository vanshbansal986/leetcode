// https://leetcode.com/problems/maximum-subarray/description/

#include<iostream>
#include<vector>
using namespace std;

int sum(vector<int> nums , int start , int end){
    int sum;
    for (int i = start; i < end; i++)
    {
        sum+=nums[i];
    }
    return sum;
}

int helper(vector<int> nums ,vector<vector<int>> dp, int start , int end){
    
    if(end - start <=0 ){
        return 0;
    }

    int max = INT_MIN;

    
    
    if(dp[start][end] != INT_MIN){
        return dp[start][end];
    }



    int i =  helper(nums , dp ,  start , end-1);
    int j =  helper(nums ,dp , start + 1 , end);
    int k =  i + j + helper(nums,dp,start+1,end-1);
    
    max = i > j? (i > k? i: k): (j > k? j: k);
    dp[start][end] = max;
    return max;
}

int max_subarray(vector<int> nums){
    int n = nums.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,INT_MIN));

    return helper(nums,dp, 0 , n-1);
}

int main(){
    return 0;
}