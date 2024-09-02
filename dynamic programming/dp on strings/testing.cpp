#include <iostream>
#include <queue>
#include<vector>
#include<unordered_map>
#include<string>
#include<unordered_set>

using namespace std;
class Solution {
public:
int tabular(string s1, string s2 , vector<vector<int>> &dp) {
    int n = s1.size();
    int m = s2.size();

    //vector < vector < int >> dp(n + 1, vector < int > (m + 1, 0));
    

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]){
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else{
                dp[i][j] = 0 + max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n][m];
}   

int tabular1(string text1, string text2 , vector<vector<int>> &dp) {
    int n = text1.size();
    int m = text2.size();
    
    //vector<vector<int>> dp(n+1 , vector<int>(m+1 , 0));

    
    
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

        for(int i = 0; i<=n; i++){
            for(int j=0; j<=m; j++){
                cout<<dp[i][j]<<" ";
            }

            cout<<endl;
        }

        cout<<endl<<endl<<endl;

        vector<vector<int>> dp1(n+1 , vector<int>(m+1 , 0));
        int ans1 = tabular1(text1 , text2 , dp1);

        for(int i = n; i>=0; i--){
            for(int j=m; j>=0; j--){
                cout<<dp1[i][j]<<" ";
            }

            cout<<endl;
        }

        //return longestSubstring(text1,text2,ans,dp1);

        return "";
    }
};