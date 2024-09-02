#include <iostream>
#include <queue>
#include<vector>
#include<unordered_map>
#include<map>
#include<string>
#include<stack>
#include<unordered_set>
using namespace std;

void graph_to_stack(int curr , vector<vector<int>>& adj , stack<int> &st , vector<int> &visited){
    int n = adj.size();
    
    visited[curr] = 1;

    for(int i=0; i < adj[curr].size(); i++){
        int adj_node = adj[curr][i];
        
        if(visited[adj_node] == -1){
            graph_to_stack(adj_node , adj , st , visited);
        }
    }

    st.push(curr);

    

}

vector<vector<int>> reverseGraph(vector<vector<int>>& adj){
    vector<vector<int>> output(adj.size());
    
    for(int i=0; i<adj.size(); i++){
        int node = i;
        for(int j=0; j<adj[i].size(); j++){
            int adj_node = adj[i][j];
            
            output[adj_node].push_back(i);
        }
    }

    return output;
}

void dfs(int curr , vector<vector<int>>& adj , stack<int> &st , vector<int> &visited,vector<int> &mini){
    visited[curr] = 1;

    
    for(int i=0; i < adj[curr].size(); i++){
        
        int adj_node = adj[curr][i];
        
        if(visited[adj_node] == -1){

            //visited[adj] = 1;
            dfs(adj_node , adj , st , visited ,mini);

        }
    }

    
}

int kosaraju(int V, vector<vector<int>>& adj){
    int n = adj.size();
    // step-1 : sorting all edges according to time visited
    stack<int> st; 
    vector<int> visited(n,-1);
    
    for (int i = 0; i < n; i++) {
        if (visited[i] == -1) {
            graph_to_stack(i, adj, st, visited);
        }
    }

    // step-2: reverse all the edges
    vector<vector<int>> reversedGraph = reverseGraph(adj);
    
    // step-3 : dfs
    fill(visited.begin(), visited.end(), -1);
    vector<vector<int>> output;

    while(!st.empty()){
        vector<int> mini;

        if(visited[st.top()] == -1){
            dfs(st.top() , reversedGraph , st , visited,mini);
            output.push_back(mini);
        }
        else{
            st.pop();
        }
    }

    return output.size();

}