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

int removeStones(vector<vector<int>>& stones){
    int n = stones.size();

    disjointSet ds(n);

    for(int i=0; i<n; i++){
        int row = stones[i][0];
        int col = stones[i][1];
        for(int j=i+1; j<n; j++){
            int adj_row = stones[j][0];
            int adj_col = stones[j][1];

            if(row == adj_row || col == adj_col){
                ds.unionByRank(i,j);
            }
        }
    }

    vector<int> parent = ds.parent;
    int count = 0;
    for(int i=0; i<n; i++){
        if(parent[i] == i){
            count++;
        }
    }

    return n-count;
}