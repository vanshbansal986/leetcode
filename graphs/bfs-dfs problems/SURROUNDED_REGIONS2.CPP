#include <iostream>
#include <queue>
#include<vector>
using namespace std;




void dfs(int i , int j , vector<vector<char>>& board , vector<vector<int>> &visited){

    int n = board.size();
    int m = board[0].size();

    board[i][j] = '#';

    //up
    if(i-1 >= 0 && board[i-1][j] == '0' && visited[i-1][j] == -1){
        visited[i-1][j] = 1;
        
        dfs(i-1,j,board,visited);

    }     
        
    // down
    if(i+1 < n && board[i+1][j] == '0' && visited[i+1][j] == -1){
        visited[i+1][j] = 1;

        dfs(i+1,j,board,visited);
    }
        
    // right
    if(j+1 < m && board[i][j+1] == '0' && visited[i][j+1] == -1){
        visited[i][j+1] = 1;

        dfs(i,j+1,board,visited);

    }

    // left
    if(j-1 >= 0 && board[i][j-1] == '0' && visited[i][j-1] == -1){
        visited[i][j-1] = 1;

        dfs(i,j-1,board,visited);
    }

}

void solve(vector<vector<char>>& board){
    int n = board.size();
    int m = board[0].size();

    vector<vector<int>> visited(n,vector<int>(m,-1));
    vector<pair<int,int>> output;
    
    // top and bottom boundry
    for(int j = 0; j < m; j++){
        if(board[0][j] == 'O'){

            visited[0][j] = 1;
            board[0][j] = '#';
            dfs(0,j,board,visited);
            
        }

        if(board[n-1][j] == 'O'){
            visited[n-1][j] = 1;
            board[n-1][j] = '#';
            dfs(n-1,j,board,visited);
        }
    }

    // left and right boundry
    for(int i = 0; i < n; i++){
        if(board[i][0] == 1){

            board[i][0] = '#';
            visited[i][0] = 1;
            
            dfs(i,0,board,visited);
        }

        if(board[i][m-1] == 1){

            board[i][m-1] = '#';
            dfs(i,m-1,board,visited);
        }
    }



    
}