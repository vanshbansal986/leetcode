#include <iostream>
#include <queue>
#include<vector>
#include<unordered_map>
#include<map>
#include<string>
#include<stack>
#include<unordered_set>
using namespace std;
#include "disjoint_rank.cpp"

int find_island_size(disjointSet ds){
    
    vector<int> parent = ds.parent_arr();
    int n = parent.size();

    int count = 0, candidate = 0;

    // Phase 1: Find a candidate for the majority element
    for (int num : parent) {
        if (count == 0) {
            candidate = num;
        }
        count += (num == candidate) ? 1 : -1;
    }

    int ans = std::count(parent.begin(), parent.end(), candidate);
    return ans;
}

int largestIsland(vector<vector<int>>& grid){
    int n = grid.size();
    
    unordered_map<pair<int,int> , int> m;
    
    int k  = 0;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            m[{i,j}] = k;
            k++;
        }
    }

    disjointSet ds(k);
    vector<int> vis(k,-1);
    int row_arr[4] = {0,0,1,-1};
    int col_arr[4] = {1,-1,0,0};

    // Initital configuration of disjoint set
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            
            if(grid[i][j] == 0){
                continue;
            }
            
            int node = m[{i,j}];

            for(int k = 0; k<4; k++){
                
                int row = i + row_arr[k];
                int col = j + col_arr[k];
                int adj_node = m[{row,col}];
                
                if(row>=0 && col>=0 && row<n && col<n && grid[row][col] == 1 && vis[adj_node] == -1){
                    //ds.unionByRank(node,adj_node);
                    ds.unionBySize(node,adj_node);
                }

            }
        }
    }

    // getting max island size in initial configuration using get size function.
    int maxi = INT_MIN;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            
            int node = m[{i,j}];
            int ult_p = ds.findUltParent(node);

            int node_size = ds.size[ult_p];

            maxi = max(maxi , node_size);
        }
    }


    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            
            if(grid[i][j] == 1){
                continue;
            }

            int node = m[{i,j}];
            disjointSet new_ds = ds;
            
            unordered_set<int> neighbours;

            for(int k = 0; k<4; k++){
                
                int row = i + row_arr[k];
                int col = j + col_arr[k];
                int adj_node = m[{row,col}];
                
                if(row>=0 && col>=0 && row<n && col<n && grid[row][col] == 1 && vis[adj_node] == -1){
                    neighbours.insert(adj_node);
                }
            }

            int island_size = 1; //new_ds.size[ds.findUltParent(node)];
            for(int component : neighbours){
                island_size += ds.size[ds.findUltParent(component)];
            }

            maxi = max(island_size , maxi);
        }
    }

    return maxi;
        
}