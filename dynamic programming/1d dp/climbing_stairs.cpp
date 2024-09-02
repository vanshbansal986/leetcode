#include <iostream>
#include <queue>
#include<vector>
#include<unordered_map>
#include<string>
#include<unordered_set>
using namespace std;

int helper1(int curr , int n , vector<int> &dp){
    if(curr >= n){
        return 0;
    }

    if(dp[curr] != -1){
        return dp[curr];
    }

    int ans = helper1(curr + 1 , n , dp) + helper1(curr + 2 , n , dp);
    dp[curr] = ans;

    return ans;
}

int tabulation(int n){
    vector<int> dp(n+1 , -1);
    dp[0] = 1;
    dp[1] = 1;

    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];

}

int climbStairs(int n) {
    vector<int> dp(n+1 , -1);

    return helper1(0,n,dp);

}