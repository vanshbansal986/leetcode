#include <iostream>
#include <queue>
#include<vector>
#include<unordered_map>
#include<string>
#include<unordered_set>
using namespace std;

int helper(int i , int j , int m , int n , vector<vector<int>> &dp){
    if(i== m-1 && j==n-1){
        return 1;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int right = 0,down = 0;
    if(j+1 < n){
        right = helper(i , j+1 , m,n,dp);
    }
    if(i+1 < m){
        down = helper(i+1, j ,m,n,dp);
    }

    return dp[i][j] = right + down;

}

int tabulation(int m , int n){
    vector<vector<int>> dp(m+1 , vector<int>(n+1, -1));
    dp[m-1][n-1] = 1;

    for(int i=m-1; i>=0; i--){
        for(int j= n-1; j>=0; j--){
            
            if( i == m-1 && j==n-1){
                continue;
            }


            int right = 0,down = 0;
            if(j+1 < n){
                right = dp[i][j+1];
            }
            if(i+1 < m){
                down = dp[i+1][j];
            }

            dp[i][j] = right + down;
        }
    }
    return dp[0][0];
}

int uniquePaths(int m, int n){
    vector<vector<int>> dp(m+1 , vector<int>(n+1, -1));
    return helper(0,0,m,n,dp);
}