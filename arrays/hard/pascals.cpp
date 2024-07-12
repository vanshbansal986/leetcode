// https://leetcode.com/problems/longest-consecutive-sequence/description/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;


vector<vector<int>> pascals(int numRows){
    int n = numRows;
    vector<vector<int>> output;

    for(int i=0; i<n; i++){
        int size = i+1;
        vector<int> mini(size);
        mini[0] = 1;
        mini[size-1] = 1;

        for(int j=1; j<size-1; j++){
            mini[j] = output[i-1][j-1] + output[i-1][j];
        }

        output.push_back(mini); 
    }

    return output;

}

int main(){
    
}

