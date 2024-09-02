#include <iostream>
#include <queue>
#include<vector>
#include<unordered_map>
#include<string>
#include<unordered_set>
using namespace std;

int helper(int i , int j , int m , int n , vector<vector<int>> &dp,vector<vector<int>>& grid){
    if(i== m-1 && j==n-1){
        return 1;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int right = 0,down = 0;
    if(j+1 < n && grid[i][j+1] != 1){
        right = helper(i , j+1 , m,n,dp,grid);
    }
    if(i+1 < m && grid[i+1][j] != 1){
        down = helper(i+1, j ,m,n,dp,grid);
    }

    return dp[i][j] = right + down;

}
int tabulation(int m , int n,vector<vector<int>>& grid){
    vector<vector<int>> dp(m+1 , vector<int>(n+1, -1));
    dp[m-1][n-1] = 1;

    for(int i=m-1; i>=0; i--){
        for(int j= n-1; j>=0; j--){
            
            if( i == m-1 && j==n-1){
                continue;
            }


            int right = 0,down = 0;
            if(j+1 < n && grid[i][j+1] != 1){
                right = dp[i][j+1];
            }
            if(i+1 < m && grid[i+1][j] != 1){
                down = dp[i+1][j];
            }

            dp[i][j] = right + down;
        }
    }
    return dp[0][0];
}

int uniquePaths(vector<vector<int>>& obstacleGrid){
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    if(obstacleGrid[0][0] == 1){
        return 0;
    }
        

    vector<vector<int>> dp(m+1 , vector<int>(n+1, -1));
    return helper(0,0,m,n,dp,obstacleGrid);
}