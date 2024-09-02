#include <iostream>
#include <queue>
#include<vector>
#include<unordered_map>
#include<map>
#include<string>
#include<stack>
using namespace std;
#include "disjoint_rank.cpp"




int swimInWater(vector<vector<int>>& grid){
    // Define the priority queue using the quadruple structure and comparator
    priority_queue<pair<int, pair<int, int>>,
                   vector<pair<int, pair<int, int>>>,
                   greater<pair<int, pair<int, int>>>> pending;
    int n = grid.size();
    vector<int> output;
    vector<vector<int>> dist(n,vector<int>(n,1e9)); 
    vector<vector<int>> vis(n,vector<int>(n,-1));
    dist[0][0] = grid[0][0];
    vis[0][0] = 1;

    pending.push({grid[0][0],{0,0}});
    int row_arr[4] = {0,0,1,-1};
    int col_arr[4] = {1,-1,0,0};


    while(!pending.empty()){
        pair<int,pair<int,int>> front = pending.top();
        int curr_eff = front.first;
        int row = front.second.first;
        int col = front.second.second;

        pending.pop();

        if(row == n-1 && col == n-1){
            return curr_eff;
        }

        for(int i=0; i<4; i++){
            int new_row = row + row_arr[i];
            int new_col = col + col_arr[i];

            if(new_row>=0 && new_col>=0 && new_row<n && new_col<n && vis[new_row][new_col] == -1){

                int new_eff = max(curr_eff , grid[new_row][new_col]);


                if(new_eff < dist[new_row][new_col]){
                    
                    dist[new_row][new_col] = new_eff;
                    vis[new_row][new_col] = 1;
                    
                    pending.push({new_eff , {new_row , new_col}});
                }
                

            }
        }
    }

    return -1;
}
