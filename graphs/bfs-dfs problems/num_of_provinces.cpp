#include <iostream>
#include <queue>
#include<vector>
using namespace std;



void helper(int curr_vertex, vector<vector<int>>& edges , vector<int> &visited , int &mini){
    
    queue<int> pending;
    pending.push(curr_vertex);
    

    while(!pending.empty()){
        int front = pending.front();
        visited[front] = 0;
        pending.pop();

        for(int i=0; i<edges.size(); i++){

            if(i == front){
                continue;
            }

            if(edges[front][i] == 1 && visited[i] == -1){
                pending.push(i);
            }
        }
    }

    for(int i = 0; i<edges.size(); i++){
        if(visited[i] == -1){
            mini += 1;
            helper(i,edges,visited,mini);
        }
    }
}

int findCircleNum(vector<vector<int>>& isConnected){
    vector<int> visited(isConnected.size() , -1);
    int mini = 0;
    helper(0,isConnected,visited,mini);        
}