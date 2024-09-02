#include <iostream>
#include <queue>
#include<vector>
#include<unordered_map>
#include<string>
#include<unordered_set>
using namespace std;

int helper(int i , int j1 , int j2 , vector<vector<int>>& grid){
    int n = grid.size();
    int m = grid[0].size();

    if(j1>=m || j2>=m || j1<0 || j2<0){
        return -1e8;
    }

    if(i == n-1){
        if(j1 == j2){
            return grid[i][j1];
        }
        return grid[i][j1] + grid[i][j2];
    }

    int arr[3] = {-1,0,1};
    int maxi = 0;
    for(int r = 0; r<3; r++){
        for(int s = 0; s<3; s++){
            int ans;
            if(j1 == j2){
                ans = grid[i][j1] + helper(i+1 , j1 + arr[r] , j2+arr[s] , grid);
            }
            else{
                ans = grid[i][j1] + grid[i][j2] + helper(i+1 , j1 + arr[r] , j2+arr[s] , grid);
            }

            maxi = max(maxi , ans);

            
        }
    }

    return maxi;
}

int solve(int n, int m, vector<vector<int>>& grid) {
    vector<vector<vector<int>>> dp(n+1  ,vector<vector<int>>(m+1 , vector<int>(m+1 , -1e8)));

    // base case
    for(int j1 = 0; j1<m; j1++){
        for(int j2 =0; j2<m; j2++){
            if(j1 == j2){
                dp[n-1][j1][j2] = grid[n-1][j1];
            }
            else{
                dp[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2];
            }
        }
    }

    int arr[3] = {-1,0,1};
    int maxi = 0;

    for(int i= n-2; i>=0; i--){
        for(int j1 = m-1; j1 >= 0; j1--){
            for(int j2 = 0; j2<m; j2++){
                for(int r = 0; r<3; r++){
                    for(int s = 0; s<3; s++){
                        int ans;
                        if(j1 == j2){
                            ans = grid[i][j1] + helper(i+1 , j1 + arr[r] , j2+arr[s] , grid);
                        }
                        else{
                            ans = grid[i][j1] + grid[i][j2] + helper(i+1 , j1 + arr[r] , j2+arr[s] , grid);
                        }

                        maxi = max(maxi , ans);


                    }
                }
            }
        }
    }

    return dp[0][0][m-1];


}

int solve(int n, int m, vector<vector<int>>& grid) {
    
}