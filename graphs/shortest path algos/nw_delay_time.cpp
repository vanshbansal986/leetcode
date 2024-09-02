#include <iostream>
#include <queue>
#include<vector>
#include<unordered_map>
#include<string>
#include<stack>
using namespace std;

int networkDelayTime(vector<vector<int>>& times, int n, int k) {

    vector<int> distance(n , INT_MAX);      

    vector<vector<pair<int,int>>> graph(n);

    for(int i=0; i<times.size(); i++){
        int v1 = times[i][0] - 1;
        int v2 = times[i][1] - 1;
        int wt = times[i][2];

        graph[v1].push_back({v2,wt});
    }

    //vector<int> visited(n,-1);

    vector<int> time(n,INT_MAX);

    queue<pair<int,int>> pending;
    pending.push({k-1,0});
    time[k-1] = 0;
    

    int total_time = -1;

    while(!pending.empty()){
        int curr = pending.front().first;
        int curr_time = pending.front().second;

        pending.pop();

        for(int i=0; i<graph[curr].size(); i++){
            int adj = graph[curr][i].first;
            int adj_time = graph[curr][i].second;
            
            int total_adj_time = curr_time + adj_time;

            if(total_adj_time < time[adj]){
                time[adj] = total_adj_time;
                pending.push({adj, time[adj]});
            }
            
            
        }
    }

    for(int i=0; i<n; i++){
        if(time[i] == INT_MAX){
            // this means we have not visited this node so network is incomplete
            return -1;
        }

        if(time[i] > total_time){
            total_time = time[i];
        }
    }

    return total_time;
}