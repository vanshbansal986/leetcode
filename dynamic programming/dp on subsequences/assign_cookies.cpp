#include <iostream>
#include <queue>
#include<vector>
#include<unordered_map>
#include<string>
#include<unordered_set>
using namespace std;


int helper(int i , int j , vector<int> greed, vector<int> size  ,  vector<vector<int>> &dp){
    int n = greed.size();
    int m = size.size();
    if(i == n || j == m){
        return 0;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int exc = helper(i , j + 1 , greed , size , dp);

    int inc = 0;
    if(greed[i] <= size[j]){
        inc = 1 + helper(i+1 , j+1 , greed , size  , dp);
    }

    return dp[i][j] = inc + exc;

}

int tabular(vector<int>& arr , int amount){
    
}


int perfectSum(vector<int>& greed, vector<int>& size) {
    int n = greed.size();
    int m = size.size();
    vector<vector<int>> dp(n+1 ,vector<int>(m+1 , -1));

    return helper(0,0,greed,size , dp);

    
}