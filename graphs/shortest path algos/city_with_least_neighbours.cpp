#include <iostream>
#include <queue>
#include<vector>
#include<unordered_map>
#include<string>
#include<stack>
using namespace std;

vector<vector<int>> edges_to_matrix(vector<vector<int>>& edges , int n){
    vector<vector<int>> matrix(n , vector<int>(n,1e9));
    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];

        matrix[u][v] = wt;
        matrix[v][u] = wt;
    }

    for(int i=0; i<n; i++){
        matrix[i][i] = 0;
    }

    return matrix;
}

int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    int t = distanceThreshold;
    vector<vector<int>> matrix = edges_to_matrix(edges,n);

    for(int k = 0; k<n; k++){
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                
                matrix[i][j] = min(matrix[i][j] , matrix[i][k]+matrix[k][j]);
            }
        }
    }

    vector<int> output(n,0);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(matrix[i][j] <= t && matrix[i][j] != 0){
                output[i]++;
                output[j]++;
            }
        }
    }

    int count  = INT_MAX;
    int city = -1;
    for(int i=0; i<n; i++){
        if(output[i] <= count){
            count = output[i];
            city = i;
        }
    }

    return city;

}