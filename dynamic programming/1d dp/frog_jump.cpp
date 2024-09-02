#include <iostream>
#include <queue>
#include<vector>
#include<unordered_map>
#include<string>
#include<unordered_set>
using namespace std;

int helper1(int curr , vector<int> &dp,vector<int>& height){
   
    if(curr == 0){
        return 0;
    }
    
    if(dp[curr] != -1){
        return dp[curr];
    }

    int step1 = 1e9;
    int step2= 1e9;
    
    step1 = abs(height[curr] - height[curr-1]) + helper1(curr-1 , dp , height);
    
    if(curr - 2 >= 0){
        step2 = abs(height[curr] - height[curr-2]) + helper1(curr-2  , dp , height); 
    }

    return dp[curr] = min(step1,step2);
}

int tabulation(int n , vector<int> height){
    vector<int> dp(n+1 , 0);
    dp[0] = 0;
    //dp[1] = 1;

    for(int curr=1; curr<=n; curr++){
        
        int step2= 1e9;
        
        int step1 = abs(height[curr] - height[curr-1]) + dp[curr-1];
        
        if(curr >= 2){
            step2 = abs(height[curr] - height[curr-2]) + dp[curr-2]; 
        }

        dp[curr] = min(step1,step2);
    }
    return dp[n];

}

// Space optimization
int tabulation2(int n , vector<int> height){
    // vector<int> dp(n+1 , 0);
    // dp[0] = 0;
    // //dp[1] = 1;

    int prev_i = 0;
    int prev_2_i = 0;
    
    int ans;
    for(int curr=1; curr<=n; curr++){
        
        int step2= 1e9;
        
        int step1 = abs(height[curr] - height[curr-1]) + prev_i;
        
        if(curr >= 2){
            step2 = abs(height[curr] - height[curr-2]) + prev_2_i; 
        }

        ans = min(step1,step2);
        
        prev_2_i = prev_i;
        prev_i = ans;
        
    }
    return prev_i;

}

int climbStairs(vector<int>& height,int n) {
    vector<int> dp(n+1 , -1);

    //return helper1(0,n-1,dp,height);

}