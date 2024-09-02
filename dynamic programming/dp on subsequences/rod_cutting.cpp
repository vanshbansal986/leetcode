#include <iostream>
#include <queue>
#include<vector>
#include<unordered_map>
#include<string>
#include<unordered_set>
using namespace std;

int helper(int i , int curr_l , vector<int> prices  , int n , vector<int> &dp){
    if(curr_l == 0){
        return 0;
    }
    
    if(dp[curr_l] != -1){
        return dp[curr_l];
    }

    priority_queue<int> mini;
    for(int j=0; j<n; j++){
        int ans = INT_MIN;
        if(curr_l - (j+1) >= 0){
            ans = prices[j] + helper(j , curr_l - (j+1)  , prices , n , dp);
        }

        mini.push(ans);
    }

    return dp[curr_l] = mini.top();
}



int tabular(vector<int>& prices ,int l){
    vector<int> dp(l+1 , -1);
    
    dp[0] = 0;

    for(int curr_l = 1; curr_l <= l; curr_l++){
            priority_queue<int> mini;
        for(int j=0; j<l; j++){
            int ans = INT_MIN;
            if(curr_l - (j+1) >= 0){
                ans = prices[j] + dp[curr_l - (j+1)];
            }

            mini.push(ans);
        }

        dp[curr_l] = mini.top();
    }

    return dp[l];
}


int perfectSum(vector<int>& prices ,int l) {
    int n = prices.size();
    vector<int> dp(n+1 , -1);

    return helper(0 , l , prices, n , dp);
    
}