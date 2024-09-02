#include <iostream>
#include <queue>
#include<vector>
#include<unordered_map>
#include<string>
#include<unordered_set>
using namespace std;

int helper(int i , int j , int count , string text1 , string text2 , vector<vector<vector<int>>> &dp){
    int n = text1.size();
    int m = text2.size();
    
    if(i == n || j == n){
        return count;
    }

    if(dp[i][j][count] != -1){
        return dp[i][j][count];
    }

    int inc = 0 , exc1 = 0 , exc2= 0;
    if(text1[i] == text2[i]){
        return dp[i][j][count] = helper(i+1, j+1 , count+1 , text1 , text2 , dp);
    }
    else{
        int exc1 = helper(i+1, j , count , text1 , text2 , dp);
        int exc2 = helper(i, j+1 , count , text1 , text2 , dp);

        return dp[i][j][count] = max(count , max(exc1 , exc2));
    }
    
}

int tabular(string text1, string text2) {
    int n = text1.size();
    int m = text2.size();
    
    vector<vector<int>> dp(n+1 , vector<int>(m+1 , 0));

    for(int i=0; i<=n; i++){
        dp[0][i] = 0;
    }
    for(int i=0; i<=m; i++){
        dp[i][0] = 0;
    }
    

    int ans = 0;
    for(int i=1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            if(text1[i-1] == text2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
                ans = max(ans , dp[i][j]);
            }
            else{
                dp[i][j] = 0;
            }
        }
    }

    return ans;
}

int tabular2(string text1, string text2) {
    int n = text1.size();
    int m = text2.size();
    
    vector<int> prev(m+1,0) , curr(m+1,0);

    int ans = 0;
    for(int i=1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            if(text1[i-1] == text2[j-1]){
                curr[j] = 1 + prev[j-1];
                ans = max(ans , curr[j]);
            }
            else{
                curr[j] = 0;
            }
        }
    }

    return ans;
}

int longestCommonSubstring(string text1, string text2) {
    int n = text1.size();
    int m = text2.size();

    int max_count = max(n,m);
    
    vector<vector<vector<int>>> dp(n+1 , vector<vector<int>>(m+1 , vector<int>(max_count+1 , -1)));

    return helper(0,0, 0 , text1 , text2 , dp);
}