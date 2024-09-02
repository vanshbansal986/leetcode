#include <iostream>
#include <queue>
#include<vector>
#include<unordered_map>
#include<string>
#include<stack>
using namespace std;

vector<int> indieTree(int V, vector<int> adj[]){
    int n = V;
    vector<int> output(n,0);
    
    for(int i=0; i<n; i++){
        for(int j=0; j<adj[i].size(); j++){
            int v = adj[i][j];
            output[v] += 1;
        }
    }

    return output;
}

vector<int> bfs(vector<int> adj[] , queue<int> pending, vector<int> indie){

    vector<int> output;

    while(!pending.empty()){

        int curr = pending.front();
        output.push_back(curr);
        pending.pop();

        for(int i=0; i<adj[curr].size(); i++){
            int v = adj[curr][i];
            indie[v] = indie[v] - 1;

            if(indie[v] == 0){
                pending.push(v);
            }
        }
    }

    return output;
}

vector<int> topoSort(int V, vector<int> adj[]){
	int n = V;
    
    //vector<int> visited(n,-1);
    queue<int> pending;

    vector<int> indie = indieTree(V , adj);

    for(int i=0; i<n; i++){
        if(indie[i] == 0){
            pending.push(i);
        }
    }

    return bfs(adj,pending,indie);
}