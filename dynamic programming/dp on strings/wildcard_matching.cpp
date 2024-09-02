#include <iostream>
#include <queue>
#include<vector>
#include<unordered_map>
#include<string>
#include<unordered_set>
using namespace std;

bool helper(int i , int j , string text1, string text2 , vector<vector<int>> &dp){
    int n = text1.size();
    int m = text2.size();

    if(i == n && j == m){
        return true;
    }

    if(j == m && i<n){
        return false;
    }

    if(i == n && j<m){
        for(int k=j; k<m; k++){
            if(text2[k] != '*'){
                return false;
            }
        }

        return true;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    
    if(text1[i] == text2[j] || text2[j] == '?'){
        return helper(i+1 , j+1 , text1 , text2 , dp);
    }
    else if(text2[j] == '*'){
        bool b = helper(i , j+1 , text1 , text2 , dp);

        bool c = helper(i+1 , j , text1 , text2 , dp);

        return b || c;
    }
    else{
        return false;
    }
}

int tabular(string text1, string text2){
    int n = text1.size();
    int m = text2.size();
    
    vector<vector<bool>> dp(n+1 , vector<bool>(m+1 , false));

    dp[n][m] = true;

    for(int k=m-1; k>=0; k--){
        if(text2[k] != '*'){
            break;
        }
        dp[n][k] = true;
    }

    for(int i = n-1; i>=0; i--){
        for(int j = m-1; j>=0; j--){
            if(text1[i] == text2[j] || text2[j] == '?'){
                dp[i][j] = dp[i+1][j+1];
            }
            else if(text2[j] == '*'){
                bool b = dp[i][j+1];

                bool c = dp[i+1][j];

                dp[i][j] = b || c;
            }
            else{
                dp[i][j] = false;
            }
        }
    }

    return dp[0][0];
}

bool isMatch(string text1, string text2){
        
    int n = text1.size();
    int m = text2.size();
    
    vector<vector<int>> dp(n+1 , vector<int>(m+1 , -1));

    return helper(0,0,text1 , text2 , dp);
}