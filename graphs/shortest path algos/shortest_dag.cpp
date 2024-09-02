#include <iostream>
#include <queue>
#include<vector>
#include<unordered_map>
#include<string>
#include<stack>
using namespace std;

vector<int> helper(int source , vector<vector<pair<int,int>>> graph , stack<int> & st){
    vector<int> distance(graph.size() , INT_MAX);
    distance[source] = 0;

    while(!st.empty()){
        int curr = st.top();
        int curr_dist = distance[curr];
        st.pop();

        for(int i = 0; i<graph[curr].size(); i++){
            int adj_node_dist = graph[curr][i].second;
            int adj_node = graph[curr][i].first;

            int new_dist = curr_dist + adj_node_dist;

            if(new_dist < distance[adj_node]){
                distance[adj_node] = new_dist;
            }
        }
    }

    return distance;
}

void topo_dfs(int curr , vector<vector<pair<int,int>>> graph , vector<int> &visited , int n , stack<int> &ans){
    
    visited[curr] = 1;
    
    for(int i=0; i<graph[curr].size(); i++){
        int v = graph[curr][i].first;
    
        if(visited[v] == -1){
            
            topo_dfs(v,graph,visited,n,ans);
        }
    }
    ans.push(curr);

}

vector<int> shortest_dag(int source , vector<vector<pair<int,int>>> graph){
    int n = graph.size();
    
    vector<int> visited(n,-1);
    stack<int> st;
    
    for(int i=0; i<n; i++){
        if(visited[i] == -1){
            topo_dfs(i,graph,visited,n,st);
        }
    }

    vector<int> output = helper(source,graph,st);

    return output;
}