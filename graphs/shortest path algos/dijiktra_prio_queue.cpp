#include <iostream>
#include <queue>
#include<vector>
#include<unordered_map>
#include<string>
#include<stack>

using namespace std;

vector<int> dijiktra(int source , vector<vector<pair<int,int>>> graph){
    int n = graph.size();

    priority_queue<pair<int,int>> pending;
    pending.push({0,source});

    vector<int> distance(n,INT_MAX);
    distance[source] = 0;

    while(!pending.empty()){
        int curr_dist = pending.top().first;
        int curr_node = pending.top().second;

        pending.pop();

        for(int i=0; i<graph[curr_node].size(); i++){
            int adj_node = graph[curr_node][i].first;
            int adj_dist = graph[curr_node][i].second;

            int total_dist = curr_dist + adj_dist;

            if(total_dist < distance[adj_node]){
                
                distance[adj_node] = total_dist;

                pending.push({total_dist,adj_node});
            }


        }
    }

    return distance;

}

vector<int> shortest_dag(int source , vector<vector<pair<int,int>>> graph){

}