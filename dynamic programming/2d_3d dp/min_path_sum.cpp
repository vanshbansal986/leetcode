#include <iostream>
#include <queue>
#include<vector>
#include<unordered_map>
#include<string>
#include<unordered_set>
using namespace std;

int helper(int i , int j , vector<vector<int>>& grid , vector<vector<int>> &dp){
    int m = grid.size();
    int n = grid[0].size();
    if(i==m-1 && j == n-1){
        return grid[i][j];
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int right = INT_MAX , down = INT_MAX;
    if( j+1 < n){
        right = grid[i][j] + helper(i,j+1,grid,dp);
    }
    if(i+1 < m){
        down = grid[i][j] + helper(i+1 , j , grid, dp);
    }

    return dp[i][j] = min(right , down);

}

int tabulation(vector<vector<int>>& grid){
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m+1 , vector<int>(n+1, -1));

    dp[m-1][n-1] = grid[m-1][n-1];
    for(int i=m-1; i>=0; i--){
        for(int j= n-1; j>=0; j--){
            
            if( i == m-1 && j==n-1){
                continue;
            }


            int right = INT_MAX,down = INT_MAX;
            if(j+1 < n){
                right = grid[i][j] + dp[i][j+1];
            }
            if(i+1 < m){
                down = grid[i][j] + dp[i+1][j];
            }

            dp[i][j] = min(right,down);
        }
    }
    return dp[0][0];
}

int uniquePaths(vector<vector<int>>& grid){
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m+1 , vector<int>(n+1, -1));
    return helper(0,0,grid,dp);
}