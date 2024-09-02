#include <iostream>
#include <queue>
#include<vector>
using namespace std;



bool helper(int start, vector<int> adj[] , vector<int> &visited ) {
    
        
    queue<pair<int,int>> pending;
    

    pending.push(make_pair(start,-1));
    visited[start] = 1;

    while(!pending.empty()){
        
        pair<int,int> front = pending.front();
        pending.pop();
        int v = front.first;
        int parent = front.second;

        bool push_nothing = true;

        for(int i=0; i<adj[v].size(); i++){
            int child = adj[v][i];

            if(visited[child] == 0){
                pending.push(make_pair(child,v));
                visited[child] = 1;
                push_nothing = false;
            }
            else if(child != parent){
                return true;
            }


        }
    }
    
    
    for(int i=0; i<visited.size(); i++){
        if(visited[i] == 0){
            bool ans = helper(i,adj,visited);
            if(ans == true){
                return true;
            }
        }
    }
    

    return false;
}

bool isCycle(int V, vector<int> adj[]) {
    vector<int> visited(V,0);
    
    return helper(0,adj,visited);
}