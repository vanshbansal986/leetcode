#include <iostream>
#include <queue>
#include<vector>
#include<unordered_map>
#include<map>
#include<string>
#include<stack>
using namespace std;
#include "disjoint_rank.cpp"

class Solution {
public:
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
struct pair_hash {
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2>& pair) const {
        return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
    }
};
int find_island_size(disjointSet ds){
    unordered_map<int, int> frequencyMap;
    vector<int> parent = ds.parent_arr();
    // Calculate the frequency of each element in the vector
    for (int num : parent) {
        frequencyMap[num]++;
    }

    // Find the element with the maximum frequency
    int maxFrequency = 0;
    int maxFrequencyElement = parent[0];
    for (const auto& entry : frequencyMap) {
        if (entry.second > maxFrequency) {
            maxFrequency = entry.second;
            maxFrequencyElement = entry.first;
        }
    }

    // Output the element with the maximum frequency
    //cout << "Element with maximum frequency: " << maxFrequencyElement << endl;
    return maxFrequency;
}



    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
    
    unordered_map<pair<int,int> , int , pair_hash> m;
    
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
                    //vis[adj_node] = 1;
                    ds.unionByRank(node,adj_node);
                    
                }

            }
        }
    }

    int maxi = find_island_size(ds);
    // int s = 0;
    // vector<int> test;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            
            if(grid[i][j] == 1){
                continue;
            }

            int node = m[{i,j}];
            disjointSet new_ds = ds;
            
            for(int k = 0; k<4; k++){
                
                int row = i + row_arr[k];
                int col = j + col_arr[k];
                int adj_node = m[{row,col}];
                
                if(row>=0 && col>=0 && row<n && col<n && grid[row][col] == 1 && vis[adj_node] == -1){
                    new_ds.unionByRank(node,adj_node);
                }
            }

            // if(s == 0){
            //     test = new_ds.parent;
            //     s++;
            // }
            int island_size = find_island_size(new_ds);
            //cout<<island_size<<endl;
            maxi = max(maxi,island_size);

        }
    }
    
    return maxi;
    }
};