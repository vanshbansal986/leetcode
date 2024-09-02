#include <iostream>
#include <queue>
#include<vector>
#include<unordered_map>
#include<string>
#include<stack>
using namespace std;

int helper(int n, vector<vector<int>>& roads , vector<int> time){

}

int countPaths(int n, vector<vector<int>>& roads) {

    vector<vector<pair<int,int>>> graph(n);

    for(int i=0; i<roads.size(); i++){
        int v1 = roads[i][0];
        int v2 = roads[i][1];
        int wt = roads[i][2];

        graph[v1].push_back({v2,wt});
        graph[v2].push_back({v1,wt});
    }

    vector<int> time(n,INT_MAX);
    vector<int> ways(n,0);
    priority_queue<pair<int, int>,
                       vector<pair<int, int>>, greater<pair<int, int>>>  pending;
    pending.push({0,0});
    time[0] = 0;
    ways[0] = 1;

     

    while(!pending.empty()){

        int curr = pending.top().second;
        int curr_time = pending.top().first;

        pending.pop();

        for(int i=0; i<graph[curr].size(); i++){
            int adj = graph[curr][i].first;
            int adj_time = graph[curr][i].second;
            
            int total_adj_time = curr_time + adj_time;

            if(total_adj_time == time[adj]){
                ways[adj] += ways[curr];
            }
            if(total_adj_time < time[adj]){
                time[adj] = total_adj_time;
                ways[adj] = ways[curr];
                pending.push({time[adj],adj});
            }
            
            
            
        }
    }

    
    
    
    return ways[n-1];
}