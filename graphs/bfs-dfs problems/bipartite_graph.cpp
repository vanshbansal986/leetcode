#include <iostream>
#include <queue>
#include<vector>
using namespace std;




bool helper(int curr , vector<vector<int>>& graph , vector<int> &visited , vector<int> &color){
    int n = graph.size();

    visited[curr] = 1;
    
    for(int j=0; j<graph[curr].size(); j++){
        int v = graph[curr][j];

        if(visited[v] == -1){
            visited[v] = 1;
            color[v] = 1 - color[curr];

            if(!helper(v,graph,visited,color)){
                return false;
            }
        }
        else{
            if(color[v] == color[curr]){
                //cout<<v<<" " << curr<<endl;
                return false;
            }
        }
    }
    

    return true;

}
bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    
    vector<int> visited(n,-1);
    vector<int> color(n,0);
    color[0] = 0;


    for(int i=0; i<graph.size(); i++){
        if(visited[i] == -1){
            visited[i] = 1;
            if(helper(i,graph,visited,color) == false){
                return false;
            }
        }
    }

    return true;
}
