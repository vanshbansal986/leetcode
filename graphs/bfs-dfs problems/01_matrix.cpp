#include <iostream>
#include <queue>
#include<vector>
using namespace std;

int bfs(vector<vector<int>>& mat , int i , int j){
    int n = mat.size();
    int m = mat[0].size();

    if(i<0 || i>= n || j<0 || j>=m){
        return INT_MAX;
    }
    if(mat[i][j] == 0){
        return 0;
    }

    int up = 1 + bfs(mat,i-1,j);
    int down = 1 + bfs(mat,i+1,j);
    int right = 1 + bfs(mat,i,j+1);
    int left = 1 + bfs(mat,i,j-1);

    return min(min(up,down),min(right,left));

}

int bfs2(vector<vector<int>>& mat , int i , int j){
    int n = mat.size();
    int m = mat[0].size();

    queue<pair<pair<int,int>,int>> pending;
    vector<vector<int>> visited(n , vector<int>(m,-1));
    pending.push(make_pair(make_pair(i,j),0));

    

    int min_dist = INT_MAX;

    while(!pending.empty()){
        pair<pair<int,int>,int> front = pending.front();
        int row = front.first.first;
        int col = front.first.second;
        int time = front.second;

        if(mat[row][col] == 0){

            if(time < min_dist){
                min_dist = time;
            }
        }


        visited[i][j] = 1;

        pending.pop();

        // up
        if(i-1 >= 0 && mat[i-1][j] == 1 && visited[i-1][j] == -1){      
            pending.push(make_pair(make_pair(i-1,j),time+1));
            visited[i-1][j] = 1;
        }       

        // down
        if(i+1 < n && mat[i+1][j] == 1 && visited[i+1][j] == -1){
            pending.push(make_pair(make_pair(i+1,j),time+1));
            visited[i+1][j] = 1;
        }

        // right
        if(j+1 < m && mat[i][j+1] == 1 && visited[i][j+1] == -1){
            pending.push(make_pair(make_pair(i,j+1),time+1));
            visited[i][j+1] = 1;
        }

        // left
        if(j-1 >= 0 && mat[i][j-1] == 1 && visited[i][j-1] == -1){
            pending.push(make_pair(make_pair(i,j-1),time+1));
            visited[i][j-1] = 1;
        }

    }


}

vector<vector<int>> helper(vector<vector<int>>& mat){
    int n = mat.size();
    int m = mat[0].size();
    
    vector<vector<int>> output(n , vector<int>(m,-1));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mat[i][j] == 0){
                output[i][j] = 0;
            }
            else{
                output[i][j] = bfs(mat,i,j);
            }
        }
    }
}


vector<vector<int>> updateMatrix(vector<vector<int>>& mat){

        
}