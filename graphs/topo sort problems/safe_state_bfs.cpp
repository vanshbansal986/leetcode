#include <iostream>
#include <queue>
#include<vector>
#include<unordered_map>
#include<string>
#include<stack>
using namespace std;

// void check_safe_bfs(int curr , vector<vector<int>>& graph , vector<int> &visited,vector<int> &output){
    
// }

vector<int> check_safe_bfs(vector<vector<int>> &adj , queue<int> pending, vector<int> indie){

    vector<int> output;

    while(!pending.empty()){

        int curr = pending.front();
        output.push_back(curr);
        pending.pop();

        for(int i=0; i<adj[curr].size(); i++){
            int v = adj[curr][i];
            indie[v] = indie[v] - 1;

            if(indie[v] == 0){
                pending.push(v);
            }
        }
    }

    return output;
}

vector<vector<int>> reverseGraph(vector<vector<int>>& graph){
    vector<vector<int>> output(graph.size());

    for(int i=0; i<graph.size(); i++){
        for(int j=0; j<graph[i].size(); j++){
            output[j].push_back(i);
        }
    }

    return output;
}

vector<int> inDegree(vector<vector<int>> adj){
    int n = adj.size();
    vector<int> output(n,0);
    
    for(int i=0; i<n; i++){
        for(int j=0; j<adj[i].size(); j++){
            int v = adj[i][j];
            output[v] += 1;
        }
    }

    return output;
}

vector<int> eventualSafeNodes(vector<vector<int>>& graph){
    int n = graph.size();
    vector<int> output;

    vector<vector<int>> reversedGraph = reverseGraph(graph);

    queue<int> pending;

    vector<int> indie = inDegree(reversedGraph);

    for(int i=0; i<n; i++){
        if(indie[i] == 0){
            pending.push(i);
        }
    }

    return check_safe_bfs(reversedGraph,pending,indie);
    

        
}