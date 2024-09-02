#include <iostream>
#include <queue>
#include<vector>
#include<unordered_map>
#include<string>
#include<unordered_set>
using namespace std;

bool helper2(int i , int j, string text1 , string text2 , vector<vector<int>> &dp1){
    if(j == text2.size()){
        return true;
    }
    if(i == text1.size()){
        return false;
    }

    if(dp1[i][j] != -1){
        return dp1[i][j];
    }

    int inc = false;
    if(text1[i] == text2[j]){
        inc = helper2(i+1 , j+1 , text1 , text2 , dp1);
    }
    
    int exc = helper2(i+1 , j , text1 , text2 , dp1);

    return dp1[i][j] = inc || exc;
    
}

bool isSubseq(string text1 , string text2){
    int n = text1.size();
    int m = text2.size();
    
    vector<vector<int>> dp1(n+1 , vector<int>(m+1, -1));

    return helper2(0,0,text1,text2,dp1);
}

int helper(int i , int prev , vector<string> words , vector<vector<int>> &dp){
    if(i == words.size()){
        return 0;
    }

    if(dp[i][prev] != -1){
        return dp[i][prev];
    }

    int inc = 0;
    if(prev == -1){
        inc = 1 + helper(i+1 , i , words , dp);
    }
    else if(words[i].size() > words[prev].size() && isSubseq(words[i] , words[prev]) == true){
        inc = 1 + helper(i+1 , i , words , dp);
    }

    int exc = helper(i+1 , prev , words , dp);

    return dp[i][prev] = max(inc,exc);
   
}





int tabular(vector<int> words){
    
}



int longestStrChain(vector<string>& words) {
    int n = words.size();

    vector<vector<int>> dp(n+1 , vector<int>(n+1 , -1));

    return helper(0,-1,words,dp);
}