#include <iostream>
#include <queue>
#include<vector>
#include<unordered_map>
#include<string>
#include<unordered_set>
using namespace std;



bool tabular_subseq(string text1 , string text2){
    int n = text1.size();
    int m = text2.size();
    
    vector<vector<bool>> dp1(n+1 , vector<bool>(m+1, false));

    for(int i=0; i<=n; i++){
        dp1[i][m] = true;
    }

    for(int i = n-1; i>=0; i--){
        for(int j=m-1; j>=0; j--){
            int inc = false;
            if(text1[i] == text2[j]){
                inc = dp1[i+1][j+1];
            }

            int exc = dp1[i+1][j];

            dp1[i][j] = inc || exc;
        }
    }

    return dp1[0][0];

}

int tabular_lis(vector<string>& words){
    int n = words.size();

    vector<vector<int>> dp(n+1 , vector<int>(n+1 , 0));

    for(int i = n-1; i>=0; i--){
        for(int prev = n-1; prev >= -1; prev--){
            int inc = 0;
            if(prev == -1){
                inc = 1 + dp[i+1][i+1];
            }
            else if(words[i].size()-1 == words[prev].size() && tabular_subseq(words[i] , words[prev]) == true){
                int new_prev = i;
                inc = 1 + dp[i+1][new_prev + 1];
            }

            int exc = dp[i+1][prev+1];

            dp[i][prev + 1] = max(inc , exc);
        }
    }

    return dp[0][0];
    
}



int longestStrChain(vector<string>& words) {
    int n = words.size();

    //vector<vector<int>> dp(n+1 , vector<int>(n+1 , -1));

    return tabular_lis(words);
}