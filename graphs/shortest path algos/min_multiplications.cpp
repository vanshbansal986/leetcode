#include <iostream>
#include <queue>
#include<vector>
#include<unordered_map>
#include<string>
#include<stack>
using namespace std;

const int mod = 1e5;

int minimumMultiplications(vector<int>& arr, int start, int end) {
    
    if(start == end){
        return 0;
    }

    int n = arr.size();
    queue<pair<int,int>> pending;
    pending.push({start,0});
    vector<int> dist(1e5,1e9);
    dist[start] = 0;

    while(!pending.empty()){
        int curr = pending.front().first;
        int time = pending.front().second;
        pending.pop();

        if(curr == end){
            return time;
        }

        for(int i=0; i<n; i++){
            int ans = (curr * arr[i])%mod;
            
            if(time+1 <= dist[ans]){
                
                dist[ans] = time+1;
                
                if(ans == end){
                    return time+1;
                }
                
                pending.push({ans,time+1});
            }
        }

    }

    return -1;
}