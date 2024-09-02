#include <iostream>
#include <queue>
#include<vector>
#include<unordered_map>
#include<string>
#include<unordered_set>
using namespace std;


int helper(int curr_wt , int n , vector<int> val , vector<int> wt , vector<int> &dp){
    if(curr_wt == 0){
        return 0;
    }
    

    if(dp[curr_wt] != -1){
        return dp[curr_wt];
    }

    priority_queue <int> mini;

    for(int j=0; j<n; j++){
        int inc = 0;
        if(curr_wt - wt[j] >= 0){
            inc = val[j] + helper(curr_wt - wt[j] , n , val , wt , dp);
        }

        //int exc = helper(j , curr_wt , n , val , wt , dp);

        mini.push(inc);

    }

    return dp[curr_wt] = mini.top();
}

int tabular(vector<int>& val ,vector<int>& wt  ,int W){
    int n = val.size();
    vector<int> dp(W+1 , 0);

    dp[0] = 0;

    for(int curr_wt = 0; curr_wt <= W; curr_wt++){
            priority_queue <int> mini;

        for(int j=0; j<n; j++){
            int inc = 0;
            if(curr_wt - wt[j] >= 0){
                inc = val[j] + dp[ curr_wt - wt[j] ];
            }

            mini.push(inc);
        }

        return dp[curr_wt] = mini.top();
    }

    return dp[W];
}


int perfectSum(vector<int>& val ,vector<int>& wt  ,int W) {
    int n = val.size();
    vector<int> dp(W+1 , -1);

    return helper(W  , n , val , wt , dp);
    
}