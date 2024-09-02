#include "disjoint_rank.cpp"

int spanningTree(int V, vector<vector<int>> adj[]){
    int n = V;
    
    vector<pair<int,pair<int,int>>> edges;
    for(int i=0; i<n; i++){
        for(int j=0; j<adj[i].size(); j++){
            int node = i;
            int adj_node = adj[i][j][0];
            int wt = adj[i][j][1];

            edges.push_back({wt,{node,adj_node}});
        }
    }

    sort(edges.begin() , edges.end());

    disjointSet ds(n);
    int mst = 0;
    for(int i=0; i<edges.size(); i++){
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        int wt = edges[i].first;


        if(ds.findUltParent(u) != ds.findUltParent(v)){
            mst += wt;
            ds.unionByRank(u,v);
        }
    }

    return mst;

}