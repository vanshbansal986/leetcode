#include <iostream>
#include <queue>
#include<vector>
#include<unordered_map>
#include<string>
#include<stack>
using namespace std;


int minimumEffortPath(vector<vector<int>>& heights) {
    int n = heights.size();
    int m = heights[0].size();

    vector<vector<int>> dist(n,vector<int>(n,1e9));     
    dist[0][0] = 0;

    int row_arr[4] = {0,0,1,-1};
    int col_arr[4] = {1,-1,0,0,};  

    priority_queue<pair<int,pair<int,int>>> pending;
    pending.push({0,{0,0}});

    while(!pending.empty()){
        int i = pending.top().second.first;
        int j = pending.top().second.second;
        int eff = pending.top().first;
        
        pending.pop();
        for(int k=0; k<n; k++){
            int row = i + row_arr[k];
            int col = j + col_arr[k];

            if(row>=0 && col>=0 && row<n && col<m){
                int new_eff = max(abs(heights[i][j] - heights[row][col]) , eff);

                if(new_eff < dist[row][col]){
                    dist[row][col] = new_eff;
                    pending.push({new_eff , {row,col}});
                }
            }
        }
    }

    return heights[n-1][n-1];

}