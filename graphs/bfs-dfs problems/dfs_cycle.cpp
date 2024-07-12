#include <iostream>
#include <queue>
#include<vector>
using namespace std;

bool helper(int curr , int parent , vector<int> adj[] , vector<int> &visited){
    visited[curr] = 1;
    
    for(int i = 0; i<adj[curr].size(); i++){
        int child = adj[curr][i];
        
        if(visited[child] == 0){
            visited[child] = 1;
            helper(child , curr , adj , visited);
        }
        else if(child != parent){
            return true;
        }
    }

    
    for(int i = 0; i<visited.size(); i++){
        if(visited[i] == 0){
            visited[i] = 1;
            bool ans = helper(i , -1 , adj , visited);

            if(ans == true){
                return true;
            }
        }
    }

    return false;
}


bool isCycle(int V, vector<int> adj[]) {
    vector<int> visited(V,0);

    return helper(0 , -1 , adj , visited);
}