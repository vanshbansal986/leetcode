#include <iostream>
#include <queue>
#include<vector>
#include<unordered_map>
#include<string>
#include<stack>
using namespace std;

class disjointSet{
public:
    vector<int> rank,parent,size;
    // constructor
    disjointSet(int n){

        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0; i<n+1; i++){
            parent[i] = i;
        }


    }

    int findUltParent(int node){
        // This function finds ultimate parent and performs path compression aswell

        if(node == parent[node]){
            return node;
        }

        return parent[node] = findUltParent(parent[node]); 
    }

    void unionByRank(int u , int v){
        int pu = findUltParent(u);
        int pv = findUltParent(v);

        if(pu == pv){
            return;
        }

        int ru = rank[pu];
        int rv = rank[pv];

        if(ru == rv){
            parent[pv] = pu;
            rank[pu] += 1;
        }
        else if(ru < rv){
            parent[pu] = pv;
        }
        else{
            parent[pv] = pu;
        }
    }

    void unionBySize(int u , int v){
        int pu = findUltParent(u);
        int pv = findUltParent(v);

        if(pu == pv){
            return;
        }

        int su = size[pu];
        int sv = size[pv];

        if(su == sv){
            parent[pv] = pu;
            size[pu] += size[pv];
        }
        else if(su < sv){
            parent[pu] = pv;
            size[sv] += size[su];
        }
        else{
            parent[pv] = pu;
            size[su] += size[sv];
        }
    }

    vector<int> parent_arr(){
        return parent;
    }
};