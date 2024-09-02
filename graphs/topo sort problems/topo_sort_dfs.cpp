#include <iostream>
#include <queue>
#include<vector>
#include<unordered_map>
#include<string>
#include<stack>
using namespace std;

void dfs(int curr , vector<int> adj[] , vector<int> &visited , int n , stack<int> &ans){
    
    visited[curr] = 1;
    
    for(int i=0; i<adj[curr].size(); i++){
        int v = adj[curr][i];
    
        if(visited[v] == -1){
            
            dfs(v,adj,visited,n,ans);
        }
    }
    ans.push(curr);

}

vector<int> topoSort(int V, vector<int> adj[]){

    int n = V;
    
    vector<int> visited(n,-1);
    stack<int> ans;
    
    for(int i=0; i<n; i++){
        if(visited[i] == -1){
            dfs(i,adj,visited,n,ans);
        }
    }

    vector<int> output;
    while(!ans.empty()){
        output.push_back(ans.top());
        ans.pop();
    }

    return output;

}