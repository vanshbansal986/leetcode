#include <iostream>
#include <queue>
#include<vector>
#include<unordered_map>
#include<string>
#include<stack>
using namespace std;

int helper(vector<vector<int>>& grid){
    int n = grid.size();
    vector<vector<int>> visited(n,vector<int>(n,-1));

    queue<pair<pair<int,int>,int>> pending;
    pending.push({{0,0},0});
    visited[0][0] = 1;

    int dist = -1;

    int row_arr[9] = {0,0,1,1,1,-1,-1,-1};
    int col_arr[9] = {1,-1,0,1,-1,0,1,-1};
    
    while(!pending.empty()){
        int i = pending.front().first.first;
        int j = pending.front().first.second;
        int len = pending.front().second;

        pending.pop();

        if(i == n-1 && j == n-1){
            dist = len;
            break;
        }


        for(int k=0; k<8; k++){
            int row = i + row_arr[k];
            int col = j + col_arr[k];

            if(row >= 0 && col >= 0 && row<n && col < n && grid[row][col] == 0 && visited[row][col] == -1){
                visited[row][col] = 1;
                pending.push({{row,col} , len+1 });

            }
        }
    }

    return dist;
}

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    return helper(grid);

}