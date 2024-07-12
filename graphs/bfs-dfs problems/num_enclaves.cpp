#include <iostream>
#include <queue>
#include<vector>
using namespace std;

void helper2(queue<pair<int,int>> &pending , vector<vector<int>>& grid){

    int n = grid.size();
    int m = grid[0].size();
    

    while(!pending.empty()){
        pair<int,int> front = pending.front();
        int i = front.first;
        int j = front.second;

        pending.pop();

        // up
        if(i-1 >= 0 && grid[i-1][j] == 1){      
            pending.push( make_pair(i-1,j) );
            grid[i-1][j] = 2;
        }       

        // down
        if(i+1 < n && grid[i+1][j] == 1){
            pending.push( make_pair(i+1,j) );
            grid[i+1][j] = 2;
        }

        // right
        if(j+1 < m && grid[i][j+1] == 1 ){
            pending.push( make_pair(i,j+1) );
            grid[i][j+1] = 2;
        }

        // left
        if(j-1 >= 0 && grid[i][j-1] == 1){
            pending.push( make_pair(i,j-1) );
            grid[i][j-1] = 2;
        }
    }

}

int helper(vector<vector<int>>& grid){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> visited;

    queue<pair<int,int>> pending;

    

    // top and bottom boundry
    for(int j = 0; j < m; j++){
        if(grid[0][j] == 1){

            grid[0][j] = 2;
            pending.push({0,j});
        }

        if(grid[n-1][j] == 1){

            grid[n-1][j] = 2;
            pending.push({n-1,j});
        }
    }

    // left and right boundry
    for(int i = 0; i < n; i++){
        if(grid[i][0] == 1){

            grid[i][0] = 2;
            pending.push({i,0});
        }

        if(grid[i][m-1] == 1){

            grid[i][m-1] = 2;
            pending.push({i,m-1});
        }
    }

    helper2(pending,grid);

    // traversing the matrix to find remaining number of ones
    int count = 0;
    
    for(int i = 0; i<n-1; i++){
        for(int j=0; j<m-1; j++){
            if(grid[i][j] == 1){
                count++;
            }
        }
    }

    return count;
}


int numEnclaves(vector<vector<int>>& grid) {
    return helper(grid);
}