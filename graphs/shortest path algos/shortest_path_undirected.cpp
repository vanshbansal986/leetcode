#include <iostream>
#include <queue>
#include<vector>
#include<unordered_map>
#include<string>
#include<stack>
using namespace std;



vector<int> shortest_dag(int source , vector<vector<int>> graph){
    int n = graph.size();
    
    vector<int> visited(n,-1);
    vector<int> distance(n,INT_MAX);
    
    queue<pair<int,int>> pending;
    pending.push({source,0});
    visited[source] = 1;

    while(!pending.empty()){
        pair<int,int> curr = pending.front();
        int node = curr.first;
        int dist = curr.second;

        pending.pop();

        distance[node] = dist;

        for(int i =0; i<graph[node].size(); i++){
            int adj = graph[node][i];

            if(visited[adj] == -1){
                visited[adj] = 1;
                pending.push({adj,dist+1});
            }
        }
    }

    return distance;
    
}