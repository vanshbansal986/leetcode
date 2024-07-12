#include <iostream>
#include <queue>
#include<vector>
using namespace std;



bool isCycle(int V, vector<int> adj[]) {
    int start = 0;
    
    queue<pair<int,int>> pending;
    vector<int> visited(V,0);

    pending.push(make_pair(0,-1));
    visited[0] = 1;

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

    return false;
}