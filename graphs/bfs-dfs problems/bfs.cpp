#include <iostream>
#include <queue>
#include<vector>
using namespace std;

vector<int> printGraphBFS(vector<vector<int>> edges){
    vector<int> visited(edges.size() , -1);
    vector<int> output;

    queue<int> pending;
    pending.push(0);

    while(!pending.empty()){
        int curr_vertex = pending.front();
        pending.pop();

        if(visited[curr_vertex] == -1){
            output.push_back(curr_vertex);
            visited[curr_vertex] = 0;
        }
        

        vector<int> curr_edges = edges[curr_vertex];
        
        for(int i=0; i<curr_edges.size(); i++){
            if(visited[curr_edges[i] == -1]){
                pending.push(curr_edges[i]);
            
            }
            
        }
    }

}