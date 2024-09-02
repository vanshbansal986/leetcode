#include <iostream>
#include <queue>
#include<vector>
#include<unordered_map>
#include<string>
#include<unordered_set>
using namespace std;

int helper2(int i , int j , vector<vector<int>>& matrix , vector<vector<int>> &dp){
    int m = matrix.size();
    int n = matrix[0].size();  

    if(j<0 || j>n-1){
        return INT_MAX;
    }

    if(i == m-1){
        return matrix[i][j];
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int down = matrix[i][j] + helper2(i+1 , j , matrix , dp);
    int down_right = matrix[i][j] + helper2(i+1 , j+1 , matrix , dp);
    int down_left = matrix[i][j] + helper2(i+1 , j-1 , matrix , dp);

    return dp[i][j] = min(min(down,down_right) , down_left);
}

int helper(int i , int j , vector<vector<int>>& matrix , vector<vector<int>> &dp){
    int m = matrix.size();
    int n = matrix[0].size();  

    int ans = INT_MAX;
    for(int j=0; j<n; j++){
        ans = min(helper2(0,j,matrix,dp) , ans);
    }

    return ans;
}


int tabulation(vector<vector<int>>& matrix){
    int m = matrix.size();
    int n = matrix[0].size();        

    vector<vector<int>> dp(m+1  ,vector<int>(n+1  , INT_MAX));
    for(int j=0; j<n; j++){
        dp[m-1][j] = matrix[m-1][j];
    }

    int ans = INT_MAX;
    for(int i = m-2; i>=0; i--){
        for(int j = n-1; j>=0; j--){


            int down = matrix[i][j] + dp[i+1][j];
            int down_left = INT_MAX;
            int down_right = INT_MAX;
            if(j+1 < n){
                down_right = matrix[i][j] + dp[i+1][j+1];
            }
            if(j-1 >= 0){
                down_left = matrix[i][j] + dp[i+1][j-1];
            }

            dp[i][j] = min(min(down,down_right) , down_left);
        }
    }
    
    int mini = dp[0][0];
    for(int j=1; j<n; j++ ){
        mini = min(mini , dp[0][j]);
    }

    return mini;
}

int minFallingPathSum(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();        

    vector<vector<int>> dp(m+1  ,vector<int>(n+1  , -1));
}