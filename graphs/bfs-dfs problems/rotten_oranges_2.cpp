#include <iostream>
#include <queue>
#include<vector>
using namespace std;

int bfs(vector<vector<int>>& grid ,vector<vector<int>> visited,vector<pair<pair<int,int>,int>> start){
    int n = grid.size();
    int m = grid[0].size();
    int total_time = 0;

    queue<pair<pair<int,int>,int>> pending;
    while(!start.empty()){
        pending.push(start.back());
        start.pop_back();
    }

    while(!pending.empty()){
        pair<pair<int,int>,int> front = pending.front();
        int i = front.first.first;
        int j = front.first.second;
        int time = front.second;

        if(time > total_time){
            total_time = 0;
        }

        visited[i][j] = 1;

        pending.pop();

        // up
        if(i-1 >= 0 && grid[i-1][j] == 1 && visited[i-1][j] == -1){      
            pending.push(make_pair(make_pair(i-1,j),time+1));
            visited[i-1][j] = 1;
        }       

        // down
        if(i+1 < n && grid[i+1][j] == 1 && visited[i+1][j] == -1){
            pending.push(make_pair(make_pair(i+1,j),time+1));
            visited[i+1][j] = 1;
        }

        // right
        if(j+1 < m && grid[i][j+1] == 1 && visited[i][j+1] == -1){
            pending.push(make_pair(make_pair(i,j+1),time+1));
            visited[i][j+1] = 1;
        }

        // left
        if(j-1 >= 0 && grid[i][j-1] == 1 && visited[i][j-1] == -1){
            pending.push(make_pair(make_pair(i,j-1),time+1));
            visited[i][j-1] = 1;
        }


            
    }

    // checking if all oranges are rotten 
    for(int i = 0; i<n; i++){
        for(int j=0; j<m; j++){
            if(visited[i][j] == -1){
                total_time = -1;
                break;
            }
        }
    } 

    return total_time;
}

int helper(vector<vector<int>>& grid){
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> visited(n,vector<int>(m,-1));

    // getting the starting rotten oranges
    vector<pair<pair<int,int> , int> > start;
    for(int i = 0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j] == 2){
                start.push_back(make_pair(make_pair(i,j),0));
            }
        }
    } 

    return bfs(grid,visited,start);

}


int orangesRotting(vector<vector<int>>& grid){
    return helper(grid);
}