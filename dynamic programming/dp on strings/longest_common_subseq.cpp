#include <iostream>
#include <queue>
#include<vector>
#include<unordered_map>
#include<string>
#include<unordered_set>
using namespace std;

int helper(int i , int j , string text1, string text2 , vector<vector<int>> &dp){
    int n = text1.size();
    int m = text2.size();

    if(i == n || j == m){
        return 0;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int inc = 0 , exc1 = 0 , exc2= 0;
    if(text1[i] == text2[j]){
        inc = 1 + helper(i+1, j+1 , text1 , text2 , dp);
    }
    else{
        exc1 = helper(i+1 , j , text1 , text2 , dp);
        exc2 = helper(i , j+1 , text1 , text2 , dp);
    }

    return max(max(exc1,exc2) , inc);
}

int tabular(string text1, string text2) {
    int n = text1.size();
    int m = text2.size();
    
    vector<vector<int>> dp(n+1 , vector<int>(m+1 , 0));

    for(int i=0; i<m; i++){
        dp[n][i] = 0;
    }
    for(int i=0; i<n; i++){
        dp[i][m] = 0;
    }
    
    for(int i = n-1; i>=0; i--){
        for(int j=m-1; j>=0; j--){
            int inc = 0 , exc1 = 0 , exc2= 0;
            if(text1[i-1] == text2[j-1]){
                inc = 1 + dp[i+1][j+1];
            }
            else{
                exc1 = dp[i+1][j];
                exc2 = dp[i][j+1];
            }

            dp[i][j] = max(max(exc1,exc2) , inc);
        }
    }

    return dp[0][0];
}

int longestCommonSubsequence(string text1, string text2) {
    int n = text1.size();
    int m = text2.size();
    
    vector<vector<int>> dp(n+1 , vector<int>(m+1 , -1));

    return helper(0,0,text1 , text2 , dp);
}