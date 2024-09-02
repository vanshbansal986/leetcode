#include <iostream>
#include <queue>
#include<vector>
#include<unordered_map>
#include<string>
#include<unordered_set>
using namespace std;

int helper(int i , int j , vector<vector<int>>& grid , vector<vector<int>> &dp){
    if(i == grid.size()-1){
        return grid[i][j];
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int down = 0 , adj_down = 0;
    if(i+1 < grid.size()){
        down = grid[i][j] + helper(i+1 , j , grid , dp);
        adj_down = grid[i][j] + helper(i+1 , j+1 , grid , dp);
    }

    return dp[i][j] = min(down,adj_down);

    
}

int tabulation(vector<vector<int>>& grid){
    int m = grid.size();
    int n = grid[m-1].size();

    vector<vector<int>> dp(m + 1  , vector<int>(m, -1));
    
    dp[0][0] = grid[0][0];

    int down = 0 , adj_down = 0;
    for(int i=1; i<m; i++){
        for(int j=0; j<grid[i].size(); j++){
            if(i+1 < grid.size()){
                down = grid[i][j] + dp[i+1][j];
                adj_down = grid[i][j] + dp[i+1][j+1];
            }

            dp[i][j] = min(down,adj_down);
        }
    }

    return dp[m-1][n-1];
}

int uniquePaths(vector<vector<int>>& triangle){
    
    vector<vector<int>> dp(triangle.size() + 1  , vector<int>(triangle.size(), -1));
    return helper(0,0,triangle,dp);
}