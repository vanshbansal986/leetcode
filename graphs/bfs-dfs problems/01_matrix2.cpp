#include <iostream>
#include <queue>
#include<vector>
using namespace std;



vector<vector<int>> bfs2(vector<vector<int>>& mat ,vector<pair<pair<int,int> , int> > start){
    int n = mat.size();
    int m = mat[0].size();

    vector<vector<int>> visited(n , vector<int>(m,-1));
    vector<vector<int>> output(n , vector<int>(m,-1));

    queue<pair<pair<int,int>,int>> pending;
    while(!start.empty()){
        pending.push(start.back());
        start.pop_back();
    }

    

    int min_dist = INT_MAX;

    while(!pending.empty()){
        
        pair<pair<int,int>,int> front = pending.front();
        int i = front.first.first;
        int j = front.first.second;
        int time = front.second;

        visited[i][j] = 1;
        output[i][j] = time;

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

    return output;


}

vector<vector<int>> helper(vector<vector<int>>& mat){
    int n = mat.size();
    int m = mat[0].size();
    
    vector<vector<int>> output(n , vector<int>(m,-1));
    
    
    // getting the starting rotten oranges
    vector<pair<pair<int,int> , int> > start;
    for(int i = 0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mat[i][j] == 0){
                start.push_back(make_pair(make_pair(i,j),0));
            }
        }
    } 

    return bfs2(mat,start);
}


vector<vector<int>> updateMatrix(vector<vector<int>>& mat){
    return helper(mat);
        
}