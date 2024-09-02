#include <iostream>
#include <queue>
#include<vector>
#include<unordered_map>
#include<string>
#include<unordered_set>
using namespace std;

int tabular(string s1, string s2 , vector<vector<int>> &dp) {
    int n = s1.size();
    int m = s2.size();

    //vector < vector < int >> dp(n + 1, vector < int > (m + 1, 0));
    

    for (int ind1 = 1; ind1 <= n; ind1++) {
        for (int ind2 = 1; ind2 <= m; ind2++) {
            if (s1[ind1 - 1] == s2[ind2 - 1]){
                dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
            }
            else{
                dp[ind1][ind2] = 0 + max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
            }
        }
    }

    return dp[n][m];
}   

string longestSubstring(string text1, string text2 , int ans , vector<vector<int>> dp){
    int n = text1.size();
    int m = text2.size();

    
    string common = "";
    int i = n;
    int j = m;
    while(i>0 && j>0){
        if(text1[i-1] == text2[j-1]){
            common += text1[i-1];
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]){
            common += text1[i-1];
            i--;
        }
        else{
            common += text2[j-1];
            j--;
        }
        
    }

    while(i>0){
        common += (text1[i-1]);
        i--;
    }
    while(j>0){
        common += (text2[j-1]);
        j--;
    }
    
    reverse(common.begin() , common.end());
    return common;
}

string shortestCommonSupersequence(string text1, string text2) {
    int n = text1.size();
    int m = text2.size();
    vector<vector<int>> dp(n+1 , vector<int>(m+1 , 0));
    int ans = tabular(text1 , text2 , dp);
    // for(int i = n; i>=0; i--){
    //     for(int j=m; j>=0; j--){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return longestSubstring(text1,text2,ans,dp);
}