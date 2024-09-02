#include <iostream>
#include <queue>
#include<vector>
#include<unordered_map>
#include<string>
#include<stack>
using namespace std;

// void helper2(int i , int j , vector<vector<int>>& grid){
//     int n = grid.size();



//     int row_arr[4] = {0,0,1,-1};
//     int col_arr[4] = {1,-1,0,0,};

//     for(int k=0; k<8; k++){
//         int row = i + row_arr[k];
//         int col = j + col_arr[k];
//         if(row >= 0 && col >= 0 && row<n && col < n && grid[row][col] == 0){
            
//             //visited[row][col] = 1;
            
//             int adj_height = grid[row][col];
//             int new_effort = adj_height - curr_height;
            
//             if(new_effort < effort){
//                 new_effort = effort;
//             }
            
//             helper2(row,col,grid);
//         }
//     }   

// }

int helper(vector<vector<int>>& grid){
    int n = grid.size();
    vector<vector<int>> visited(n,vector<int>(n,-1));

    queue<pair<pair<int,int>,int>> pending;
    pending.push({{0,0},grid[0][0]});
    visited[0][0] = 1;

    int dist = -1;

    int row_arr[4] = {0,0,1,-1};
    int col_arr[4] = {1,-1,0,0,};
    
    while(!pending.empty()){
        int i = pending.front().first.first;
        int j = pending.front().first.second;
        int effort = pending.front().second;

        int curr_height = grid[i][j];

        pending.pop();

        
        if(i == n-1 && j == n-1){
            if(effort < dist){
                dist = effort;
            }  
        }


        for(int k=0; k<8; k++){
            int row = i + row_arr[k];
            int col = j + col_arr[k];

            if(row >= 0 && col >= 0 && row<n && col < n && grid[row][col] == 0 && visited[row][col] == -1){
                visited[row][col] = 1;
                
                int adj_height = grid[row][col];
                int new_effort = adj_height - curr_height;
                
                if(new_effort < effort){
                    new_effort = effort;
                }
                pending.push({{row,col} , new_effort });

            }
        }
    }

    return dist;
}

int minimumEffortPath(vector<vector<int>>& heights) {
    
}