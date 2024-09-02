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

    if(i == n){
        return m-j;
    }

    if(j == m){
        return n-i;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    if(text1[i] == text2[j]){
        return dp[i][j] = 0 + helper(i+1, j+1 ,text1 , text2 , dp);
    }
    else{
        int insert = 1 + helper(i , j+1 , text1 , text2 , dp);
        int dlt =  1 + helper(i+1 , j, text1 , text2 , dp);
        int replace =  1 + helper(i+1 , j+1, text1 , text2 , dp);

        return dp[i][j] = min(insert , min(dlt,replace));
    }

}

int tabular(string text1, string text2) {
    int n = text1.size();
    int m = text2.size();
    
    vector<vector<int>> dp(n+1 , vector<int>(m+1 , -1));

    for(int i=0; i<=n; i++){
        dp[i][m] =  n-i; 
    }

    for(int j=0; j<=m; j++){
        dp[n][j] =  m-j; 
    }

    for(int i = n-1; i>=0; i--){
        for(int j = m-1; j>=0; j--){
            if(text1[i] == text2[j]){
                dp[i][j] = 0 + dp[i+1][j+1];
            }
            else{
                int insert = 1 + dp[i][j+1];
                int dlt =  1 + dp[i+1][j];
                int replace =  1 + dp[i+1][j+1];

                dp[i][j] = min(insert , min(dlt,replace));
            }
        }
    }

    return dp[0][0];
}

int edit_dist(string text1, string text2){
        
    int n = text1.size();
    int m = text2.size();
    
    vector<vector<int>> dp(n+1 , vector<int>(m+1 , -1));

    
}