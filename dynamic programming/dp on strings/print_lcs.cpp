#include <iostream>
#include <queue>
#include<vector>
#include<unordered_map>
#include<string>
#include<unordered_set>
using namespace std;


int tabular(string text1, string text2 , vector<vector<int>> &dp) {
    int n = text1.size();
    int m = text2.size();
    
    
 
    for(int i = n-1; i>=0; i--){
        for(int j=m-1; j>=0; j--){
            int inc = 0 , exc1 = 0 , exc2= 0;
            if(text1[i] == text2[j]){
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

string longestSubstring(string text1, string text2 , int ans , vector<vector<int>> dp){
    int n = text1.size();
    int m = text2.size();

    vector<char> longest(ans);
    
    int k = ans;
    int i = n;
    int j = m;
    while(i>0 || j>0){
        if(text1[i-1] == text2[j-1]){
            longest[k] = text1[i-1];

            i--;
            j--;
        }
        else{
            if(dp[i-1][j] > dp[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }
    }

    string op = "";
    for(int i=0; i<ans; i++){
        op += longest[i];
    }

    return op;
}

string longestCommonSubsequence(string text1, string text2) {
    int n = text1.size();
    int m = text2.size();
    
    vector<vector<int>> dp(n+1 , vector<int>(m+1 , 0));

    int ans = tabular(text1 , text2 , dp);

    return longestSubstring(text1,text2,ans,dp);
}