#include <iostream>
#include <queue>
#include<vector>
#include<unordered_map>
#include<map>
#include<string>
#include<stack>
#include<unordered_set>
using namespace std;


int timer = 1;

void dfs(int node , int parent , vector<int> &time,vector<int> &low,vector<int> &visited , vector<vector<int>>& connections , vector<vector<int>> &bridges){

    visited[node] = 1;
    time[node] = low[node] = timer;
    timer++;

    for(int i=0; i<connections[node].size(); i++){
        int adj_node = connections[node][i];

        if(adj_node == parent){
            continue;
        }

        if(visited[adj_node] == -1){
            dfs(adj_node , node , time,low,visited,connections,bridges);

            // node is greedy. if adj_node has less time that itself it will take it
            low[node] = min(low[node] , low[adj_node]);

            // now after this it will check if bridge is there or not
            if(low[adj_node] > time[node]){
                bridges.push_back({node,adj_node});
            }
        }
        else{
            low[node] = min(low[node] , low[adj_node]);
        }
    }
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    vector<vector<int>> graph(n);  
    for(int i=0; i<connections.size(); i++){
        int u = connections[i][0];
        int v = connections[i][1];

        graph[u].push_back(v);
        graph[v].push_back(u);

    }

    vector<int> time(n);
    vector<int> low(n);
    vector<int> visited(n,-1);
    vector<vector<int>> bridges;
    dfs(0,-1,time,low,visited,connections,bridges);

    return bridges;
}