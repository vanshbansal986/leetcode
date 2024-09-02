#include <iostream>
#include <queue>
#include<vector>
#include<unordered_map>
#include<string>
#include<stack>
using namespace std;

#include "disjoint_rank.cpp"

int makeConnected(int n, vector<vector<int>>& connections){
    disjointSet ds(n);

    int extra_edges = 0;

    for(int i=0; i<connections.size(); i++){
        int u = connections[i][0];
        int v = connections[i][1];
        
        if(ds.findUltParent(u) != ds.findUltParent(v)){
            ds.unionByRank(u,v);
        }
        else{
            extra_edges++;
        }
    }

    vector<int> parent = ds.parent_arr();

    int connected_components = 0;
    for(int i=0; i<n; i++){
        if(parent[i] == i){
            connected_components++;
        }
    }

    if(connected_components <= extra_edges){
        return connected_components;
    }
    else{
        return -1;
    }
    
}