#include <iostream>
#include <queue>
#include<vector>
#include<unordered_map>
#include<string>
#include<unordered_set>
using namespace std;

int helper(int i , int j , string text1 , vector<vector<int>> &dp){
    if(i>j){
        return 0;
    }

    if(i == j){
        if(text1[i] == text1[j]){
            return 1;
        }
        else{
            return 0;
        }
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    if(text1[i] == text1[j]){
        return dp[i][j] = 2 + helper(i+1 , j-1 , text1 , dp);
    }
    else{
        int exc1 = helper(i+1 , j , text1 , dp);
        int exc2 = helper(i , j-1 , text1 , dp);

        return dp[i][j] =  max(exc1,exc2);
    }
}

int tabular(string text1) {
    int n = text1.size();
    
    vector<vector<int>> dp(n+1 , vector<int>(n+1 , 0));

    for(int i=0; i<=n; i++){
        dp[i][i] = 1;
    }

    for(int i = n-1; i>=0; i--){
        for(int j=0; j<=n; j++){
            if(text1[i] == text1[j]){
                dp[i][j] = 1 + dp[i+1][j-1];
            }
            else{
                int exc1 = dp[i+1][j];
                int exc2 = dp[i][j-1];

                dp[i][j] = max(exc1,exc2);
            }
        }
    }

    return dp[0][n];
}

int longestPalindromeSubseq(string text1) {
    int n = text1.size();
    
    vector<vector<int>> dp(n+1 , vector<int>(n+1 , -1));

    return helper(0,n-1,text1, dp);
}