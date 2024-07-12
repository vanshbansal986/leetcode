#include <iostream>
#include <queue>
#include<vector>
using namespace std;

bool onEdge(int i , int j , vector<vector<char>>& board){
    int n = board.size();
    int m = board[0].size();

    if(i == n-1 || i == 0 || j == m-1 || j == 0){
        return true;
    }

    return false;
}


bool dfs(int i , int j , vector<vector<char>>& board , vector<vector<int>> &visited,vector<pair<int,int>> &output){

    int n = board.size();
    int m = board[0].size();
    // Check if the current cell is on the edge
    
    if (onEdge(i, j, board)) {
        return false;
    }
    
    visited[i][j] = 1;

    //up
    if(i-1 >= 0 && board[i-1][j] == '0' && visited[i-1][j] == -1){
        visited[i-1][j] = 1;
        
        if(dfs(i-1,j,board,visited,output) == true ){
            output.push_back({i-1,j});
        }

    }     
        
    // down
    if(i+1 < n && board[i+1][j] == '0' && visited[i+1][j] == -1){
        visited[i+1][j] = 1;

        if(dfs(i+1,j,board,visited,output) == true ){
            output.push_back({i+1,j});
        }
    }
        
    // right
    if(j+1 < m && board[i][j+1] == '0' && visited[i][j+1] == -1){
        visited[i][j+1] = 1;

        if(dfs(i,j+1,board,visited,output) == true ){
            output.push_back({i,j+1});
        }

    }

    // left
    if(j-1 >= 0 && board[i][j-1] == '0' && visited[i][j-1] == -1){
        visited[i][j-1] = 1;

        if(dfs(i,j-1,board,visited,output) == true ){
            output.push_back({i,j-1});
        }


    }

    return true;

}

void solve(vector<vector<char>>& board){
    int n = board.size();
    int m = board[0].size();

    vector<vector<int>> visited(n,vector<int>(m,-1));
    vector<pair<int,int>> output;
    
    for(int i=0; i<n-1; i++){
        for(int j=0; j<m-1; j++){
            if(board[i][j] == '0' && visited[i][j] != -1){
                visited[i][j] = 1;
                output.push_back({i,j});
                dfs(i,j,board,visited,output);

            }
        }
    }

    for(int k=0; k<output.size(); k++){
        int i = output[i].first;
        int j = output[i].second;

        board[i][j] = 'X';
    }
}