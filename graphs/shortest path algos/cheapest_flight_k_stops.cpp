#include <iostream>
#include <queue>
#include<vector>
#include<unordered_map>
#include<string>
#include<stack>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

    vector<int> distance(n , INT_MAX);      

    vector<vector<pair<int,int>>> graph(n);

    for(int i=0; i<flights.size(); i++){
        int v1 = flights[i][0];
        int v2 = flights[i][1];
        int wt = flights[i][2];

        graph[v1].push_back({v2,wt});
    }


    distance[src] = 0;
    queue<pair<pair<int,int>,int>> pending;
    pending.push({{src,0},-1});


    int min_dist = INT_MAX;

    while(!pending.empty()){
        
        int curr = pending.front().first.first;
        int curr_dist = pending.front().first.second;
        int stops = pending.front().second;

        pending.pop();

        if(curr == dst && stops <= k){
            if(curr_dist < min_dist){
                min_dist = curr_dist;
            }
        }

        for(int i=0; i<graph[curr].size(); i++){
            
            int adj = graph[curr][i].first;
            int adj_dist = graph[curr][i].second;

            int total_dist = curr_dist + adj_dist;

            if(total_dist < distance[adj]){
                distance[adj] = total_dist;

                pending.push({ {adj , adj_dist} , stops+1 });
            }
        }
    }

    return min_dist;
    
}