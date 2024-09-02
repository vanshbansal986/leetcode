#include <iostream>
#include <queue>
#include<vector>
#include<unordered_map>
#include<string>
#include<unordered_set>
#include<queue>
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

vector<string> longestSubstring(string text1, string text2 , int ans , vector<vector<int>> dp){
    int n = text1.size();
    int m = text2.size();

    
    vector<vector<int>> visited(n+1 , vector<int>(m+1 , -1));

    queue<pair<pair<int,int> , string>> pending;
    pending.push({{n,m} , ""});
    
    unordered_set<string> string_set;
    
    unordered_map<string , int> m;

    while(!pending.empty()){
        int i = pending.front().first.first;
        int j = pending.front().first.second;
        string st = pending.front().second;

        pending.pop();

        if(st.size() == ans){
            reverse(st.begin() , st.end());
            string_set.insert(st);
        }

        if(i == 0 || j == 0){
            continue;
        }

        // if(visited[i][j] == 1 && mp.count(st) != 0){
        //     continue;
        // }

        if(text1[i-1] == text2[j-1]){
            pending.push({{i-1,j-1}, st + text1[i-1]});
        }
        else{
            pending.push({{i-1,j}, st });
            pending.push({{i,j-1}, st });
            
            // if(dp[i-1][j] == dp[i][j-1]){
            //     pending.push({{i-1,j}, st });
            //     pending.push({{i,j-1}, st });
            // }
            // else if(dp[i-1][j] > dp[i][j-1]){
            //     pending.push({{i-1,j}, st });
            // }
            // else{
            //     pending.push({{i,j-1}, st });
            // }
        }

        //visited[i][j] = 1;        
    } 

    vector<string> output;
    for (const auto& str : string_set) {
        output.push_back(str);
    }

    sort(output.begin() , output.end());

    return output;
}

string longestCommonSubsequence(string text1, string text2) {
    int n = text1.size();
    int m = text2.size();
    
    vector<vector<int>> dp(n+1 , vector<int>(m+1 , 0));

    int ans = tabular(text1 , text2 , dp);

    //return longestSubstring(text1,text2,ans,dp);
}