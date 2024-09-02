#include <iostream>
#include <queue>
#include<vector>
#include<unordered_map>
#include<string>
#include<stack>
using namespace std;

void shortest_distance(vector<vector<int>>&matrix){
    int n = matrix.size();
    for(int k = 0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                
                if(i == k || j == k){
                    continue;
                }

                if(matrix[i][j] == -1){
                    matrix[i][j] = INT_MAX;
                }

                if(matrix[i][k] + matrix[k][j] < matrix[i][j]){
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                }
            }
        }
    }

    

}