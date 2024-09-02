#include <iostream>
#include <queue>
#include<vector>
#include<unordered_map>
#include<string>
#include<stack>
using namespace std;

vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
    int n = V;
    vector<int> dist(n,INT_MAX);

    // make distance of source = 0
    dist[S] = 0;

    for(int i=0; i<n-1; i++){
        for(int j=0; j<edges.size(); j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if(dist[u] + wt < dist[v]){
                dist[v] = dist[u] + wt;
            }
        }
    }

    // check for negative edge cycle by performing one more iteration i.e Nth iteration
    for(int j=0; j<edges.size(); j++){
        int u = edges[j][0];
        int v = edges[j][1];
        int wt = edges[j][2];

        if(dist[u] + wt < dist[v]){
            return {-1};
        }
    }

    return dist;
    
}