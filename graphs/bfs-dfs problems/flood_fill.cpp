#include <iostream>
#include <queue>
#include<vector>
using namespace std;



vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color){
    int n = image.size();
    int m = image[0].size();
    int start = image[sr][sc];
    
    vector<vector<int>> visited(n , vector<int>(m,0));

    vector<vector<int>> output = image;
    queue<pair<int,int>> pending;
    
    pending.push({sr,sc});
    visited[sr][sc] = 1;
    output[sr][sc] = color;

    while(!pending.empty()){
        pair<int,int> front = pending.front();
        int i = front.first;
        int j = front.second;
        //int time = front.second;

        //visited[i][j] = 1;

        pending.pop();

        // up
        if(i-1 >= 0 && image[i-1][j] == 1 && visited[i-1][j] == -1){      
            pending.push( make_pair(i-1,j) );
            visited[i-1][j] = 1;
            output[i-1][j] = color;
        }       

        // down
        if(i+1 < n && image[i+1][j] == 1 && visited[i+1][j] == -1){
            
            pending.push( make_pair(i+1,j) );
            visited[i+1][j] = 1;
            output[i+1][j] = color;
        }

        // right
        if(j+1 < m && image[i][j+1] == 1 && visited[i][j+1] == -1){
            pending.push( make_pair(i,j+1) );
            visited[i][j+1] = 1;
            output[i][j+1] = color;
        }

        // left
        if(j-1 >= 0 && image[i][j-1] == 1 && visited[i][j-1] == -1){
            pending.push( make_pair(i,j-1) );
            visited[i][j-1] = 1;
            output[i][j-1] = color;
        }
    }
    
    return output;
}