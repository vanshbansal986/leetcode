#include <iostream>
#include <queue>
#include<vector>
#include<unordered_map>
#include<string>
#include<stack>
using namespace std;

int find_min_node(vector<int> visited , vector<int> weight){
    int n = weight.size();
    int min_wt = INT_MAX;
    int index = -1;
    
    vector<int> output;
    
    for(int i=0; i<n; i++){
        if(visited[i] == -1){
            if(weight[i] < min_wt){
                min_wt = weight[i];
                index = i;
            }
        }
    }

    return index;
}

int prims(int V, vector<vector<int>> adj[]){
    
    int n = adj->size();

    vector<int> weight(n,1e9);
    vector<int> visited(n,-1);
    vector<int> parent(n,-1);

    queue<int> pending;
    pending.push(0);
    weight[0] = 0;
    
    int count = 0;
   
    while(count < n-1){
        
        int curr = find_min_node(visited , weight);
        
        if(curr == -1){
            break;
        }
        
        visited[curr] = 1;
        

        for(int i=0; i<adj[curr].size(); i++){
            
            int adj_node = adj[curr][i][0];
            int adj_wt = adj[curr][i][1];


            if(visited[adj_node] == -1 && adj_wt < weight[adj_node]){
                weight[adj_node] = adj_wt;
                parent[adj_node] = curr;
            }
        }

        count++;
        
    }

    int mst = 0;
    for(int i=1; i<n; i++){
        mst += weight[i];
    }

    return mst;
}